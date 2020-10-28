
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
   ;

type
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
//*****  Внешние методы *****

constructor  TCppObjectBlock.Create;
begin
  inherited;
  m_libHanle := 0;
  m_moduleIndex := -1;
end;

destructor   TCppObjectBlock.Destroy;
begin
  inherited;
  if m_libHanle <> 0 then begin
    m_libHanle := 0;
    if (m_moduleIndex <> -1) AND (@destroyCM <> nil) then begin
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
  trimStr : String;
  returnCode : NATIVEINT;
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
 Result := r_Success;
  case Action of
    f_Stop: begin
     
    end;
    f_InitObjects: begin
     
    end;
    f_InitState: begin
      
    end;
    f_GoodStep: begin
      
    end;
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
      ErrorEvent(ParamName, msError, VisualObject);
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
  count: Integer;
begin
  //SetCondPortCount(VisualObject, count,  pmInput,  PORT_TYPE, sdLeft,  'inport');
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
end;
end.


