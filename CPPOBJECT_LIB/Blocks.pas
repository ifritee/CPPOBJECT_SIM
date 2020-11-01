
 //**************************************************************************//
 // Данный исходный код является составной частью системы МВТУ-4             //
 // Программист:        Никишин Е.В.                                        //
 //**************************************************************************//


unit Blocks;

 //***************************************************************************//
 //  Блоки для обмена данными через последовательный интерфейс ARNIC 429      //
 //***************************************************************************//

interface

uses
     Classes
   , DataTypes
   , RunObjts
   , Winapi.Windows
   //, Classes, MBTYArrays, DataTypes, SysUtils, RunObjts, math, tbls,
   //  TimeWinFuncs, FourierFuncs, ufftwrapper, uBaseFiltersCalc
   ;

type
  //----- Данные для изменения порта -----
  TPortData = record
    m_count: Integer;  //  количество
    m_mode: Integer;   //  режим по умолчанию
    m_type: Integer;   //  тип связи по умолчанию
    m_side: byte;      //  расположение порта по умолчанию
  end;

  //----- Данные для условного изменения порта -----
  TCondPortData = record
    m_count:Integer;          //  количество портов
    m_mode: Integer;          //  режим портов
    m_type: Integer;          //  тип связи портов
    m_side: byte;             //  расположение порта по умолчанию
    m_name: Array [0..127] of AnsiChar; //  шаблон имени портов
    m_portVariant: Integer;   //  вариант порта
  end;
  // Блок - встроенный клиент OPC
  // по умолчанию настроен на тестовый сервер Matricon
  TCppObjectBlock = class(TRunObject)
  public
    constructor  Create(Owner: TObject);override;
    destructor   Destroy;override;
    function     InfoFunc(Action: integer;aParameter: NativeInt):NativeInt;override;
    function     RunFunc(var at,h : RealType;Action:Integer):NativeInt;override;
    function     GetParamID(const ParamName:string;var DataType:TDataType;var IsConst: boolean):NativeInt;override;
    procedure    RestartSave(Stream: TStream);override;
    function     RestartLoad(Stream: TStream;Count: integer;const TimeShift:double):boolean;override;
    procedure    EditFunc(Props:TList;
                          SetPortCount:TSetPortCount;
                          SetCondPortCount:TSetCondPortCount;
                          ExecutePropScript:TExecutePropScript
                          ); override;

  strict private
    m_nextTime: double; // Целевое время
    m_libHanle : THandle; // Хендл загруженной библиотеки
    m_moduleIndex : Integer; // Индекс загруженного модуля
    //----- Методы библиотеки -----
    // Загрузка модуля
    procedure LoadModuleLibrary(name : AnsiString);

  end;

implementation

uses
     Info
   , SysUtils
   , CppObject_texts
   , IntArrays
   , RealArrays
   , uByteOperations
   , DataObjts
   , InterfaceUnit
   , StrUtils
   ;

var
  //----- Методы из библиотеки модуля -----
  createCM : function() : Integer; stdcall;
  destroyCM : procedure(number : Integer); stdcall;
  infoFuncCM : function(index: Integer; Action : Integer; aParameter : NATIVEINT) : NATIVEINT; stdcall;
  getParamIDCM : function(index: Integer; ParamName: PAnsiChar; var DataType:TDataType;var IsConst: boolean) : NATIVEINT; stdcall;
  getMultiselectQty : function(index : Integer) : Integer; stdcall;
  addMultiselect : procedure(index : Integer; multiselect : Pointer); stdcall;
  getMultiselect : function(index : Integer; number : Integer) : Pointer; stdcall;
  editFuncCM : procedure(index : Integer); stdcall;
  getPortDataQty : function(index : Integer) : Integer; stdcall;
  getCondPortDataQty : function(index : Integer) : Integer; stdcall;
  getPortData : function(index : Integer; number : Integer) : TPortData; stdcall;
  getCondPortData : function(index : Integer; number : Integer) : TCondPortData; stdcall;
  runFuncCM : function(index : Integer; var at : Double; var h : Double; Action : Integer) : NativeInt; stdcall;
  //*****  Внешние методы *****

constructor  TCppObjectBlock.Create;
begin
  inherited;
  m_libHanle := 0;
  m_moduleIndex := -1;
end;

destructor   TCppObjectBlock.Destroy;
var
  I: Integer;
  multiselect : TMultiselect;
begin
  inherited;
  if m_libHanle <> 0 then begin
    m_libHanle := 0;
    if (m_moduleIndex <> -1) AND (@destroyCM <> nil) then begin
      if (@getMultiselectQty <> nil) AND (@getMultiselect <> nil) then begin
        for I := 0 to getMultiselectQty(m_moduleIndex) - 1 do begin
          Pointer(multiselect) := getMultiselect(m_moduleIndex, I);
          multiselect.Free;
        end;
      end;
      destroyCM(m_moduleIndex);
      m_moduleIndex := -1;
    end;
    FreeLibrary(m_libHanle);
  end;
end;

function TCppObjectBlock.InfoFunc(Action: integer;aParameter: NativeInt):NativeInt;
var
  elementInfo : TElementInfo;
  List : TArray<String>;
  returnCode : NATIVEINT;
  multiSelect : TMultiSelect;
  I : Integer;
begin
  Result := 0;
  if Action = i_HaveSpetialEditor then begin
    //  Берем имя файла библиотеки
    DllInfo.Main.GetElementInfo(VisualObject, elementInfo);
    List := elementInfo.CalcTemplate^.Split([#$D#$A]);
    if Length(List) < 4 then begin
      ErrorEvent(txtCppObj_er_NoSetDll, msError, VisualObject);
      Exit;
    end;
    LoadModuleLibrary(AnsiString(DllInfo.Main.SearchPath^) + AnsiString(List[3]));
    if @createCM <> nil then begin
      m_moduleIndex := createCM;
    end;
    if (@getMultiselectQty <> nil) AND (@addMultiselect <> nil) then begin
      for I := 0 to getMultiselectQty(m_moduleIndex) - 1 do begin
        multiSelect := TMultiSelect.Create;
        addMultiselect(m_moduleIndex, multiSelect);
      end;
    end;


  end else begin
    if (m_moduleIndex = -1) OR (@infoFuncCM = nil) then begin
      ErrorEvent(txtCppObj_er_NoSetDll + 'infoFuncCM', msError, VisualObject);
      Exit;
    end;
    returnCode := infoFuncCM(m_moduleIndex, Action, aParameter);
    if returnCode = -1 then begin
      Result:=inherited InfoFunc(Action,aParameter);
    end;
  end;
end;

function TCppObjectBlock.RunFunc;
begin
  Result := r_Fail;
  if @runFuncCM <> nil then begin
    Result := runFuncCM(m_moduleIndex, at, h, Action);
  end;
end;

function TCppObjectBlock.GetParamID(const ParamName : string;
                                    var DataType : TDataType;
                                    var IsConst : boolean) : NativeInt;
begin
  Result:=inherited GetParamId(ParamName,DataType,IsConst);
  if Result = -1 then begin
    if @getParamIDCM <> nil then begin
      Result:= getParamIDCM(m_moduleIndex, PAnsiChar(AnsiString(ParamName)), DataType, IsConst);
    end;
  end;
end;

procedure TCppObjectBlock.RestartSave(Stream: TStream);
begin
  inherited;
  Stream.Write(m_nextTime, SizeOf(double));
end;

function TCppObjectBlock.RestartLoad(Stream: TStream;Count: integer;const TimeShift:double):boolean;
begin
  Result:=inherited RestartLoad(Stream,Count,TimeShift);
  Stream.Read(m_nextTime, SizeOf(double));
  m_nextTime := m_nextTime - TimeShift;
end;

procedure TCppObjectBlock.EditFunc;
var
  I: Integer;
  portData : TPortData;
  condPortData: TCondPortData;
begin
  if @editFuncCM <> nil then begin
    editFuncCM(m_moduleIndex); // Запуск формирования данных управления визуализацией
    //-----
    if (@getPortDataQty <> nil) AND (@getPortData <> nil) then begin
      for I := 0 to getPortDataQty(m_moduleIndex) -1 do begin
        portData := getPortData(m_moduleIndex, I);
        if portData.m_mode > -1 then begin
          SetPortCount(VisualObject, portData.m_count, TPortMode(portData.m_mode), portData.m_type,
                       portData.m_side);
        end;
      end;
    end;
    //-----
    if (@getCondPortDataQty <> nil) AND (@getCondPortData <> nil) then begin
      for I := 0 to getCondPortDataQty(m_moduleIndex) -1 do begin
        condPortData := getCondPortData(m_moduleIndex, I);
        if condPortData.m_mode > -1 then begin
          SetCondPortCount(  VisualObject
                           , condPortData.m_count
                           , TPortMode(condPortData.m_mode)
                           , condPortData.m_type
                           , condPortData.m_side
                           , String(condPortData.m_name)
                           , condPortData.m_portVariant);
        end;
      end;
    end;
  end;
end;

procedure TCppObjectBlock.LoadModuleLibrary(name : AnsiString);
var
  fullPathTo: String;
begin
  if m_libHanle <> 0 then begin // Перегружаем модуль каждый раз при запуске
    FreeLibrary(m_libHanle);
    m_libHanle := 0;
  end;
  if NOT FileExists(String(name)) then begin
    ErrorEvent(txtCppObj_er_ModuleNotFound, msError, VisualObject);
    Exit;
  end;
  fullPathTo := ExpandFileName(String(name));
  m_libHanle := LoadLibrary(PChar(fullPathTo));
  if m_libHanle = 0 then begin
    ErrorEvent(SysErrorMessage(GetLastError), msError, VisualObject);
    Exit;
  end;
  @createCM := GetProcAddress(m_libHanle, 'createModule');
  @destroyCM := GetProcAddress(m_libHanle, 'destroyModule');
  @infoFuncCM := GetProcAddress(m_libHanle, 'infoFunc');
  @getParamIDCM := GetProcAddress(m_libHanle, 'getParamID');
  @getMultiselectQty := GetProcAddress(m_libHanle, 'getMultiselectQty');
  @addMultiselect := GetProcAddress(m_libHanle, 'addMultiselect');
  @getMultiselect := GetProcAddress(m_libHanle, 'getMultiselect');
  @editFuncCM := GetProcAddress(m_libHanle, 'editFunc');
  @getPortDataQty := GetProcAddress(m_libHanle, 'getPortDataQty');
  @getCondPortDataQty := GetProcAddress(m_libHanle, 'getCondPortDataQty');
  @getPortData := GetProcAddress(m_libHanle, 'getPortData');
  @getCondPortData := GetProcAddress(m_libHanle, 'getCondPortData');
  @runFuncCM := GetProcAddress(m_libHanle, 'runFunc');
end;
end.


