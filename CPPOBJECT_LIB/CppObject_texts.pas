
 //**************************************************************************//
 // Данный исходный код является составной частью системы МВТУ-4             //
 // Программист:        Никишин Е. В.                                       //
 //**************************************************************************//


unit CppObject_texts;

interface

const

{$IFNDEF ENG}
  txtCppObj_er_NoSetDll = 'Не задана внешняя DLL';
  txtCppObj_er_ModuleNotFound = 'Файл DLL модуля не найден';
  txtCppObj_er_FuncNotFound = 'Функция в библиотеке не найдена ';


{$ELSE}
  txtCppObj_er_NoSetDll = 'External DLL not set';
  txtCppObj_er_ModuleNotFound = 'Module DLL not found';
  txtCppObj_er_FuncNotFound = 'Function in lib not found ';

{$ENDIF}

implementation

end.
