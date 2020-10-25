
 //**************************************************************************//
 // Данный исходный код является составной частью системы МВТУ-4             //
 // Программист:        Никишин Е. В.                                       //
 //**************************************************************************//


unit CppObject_texts;

interface

const

{$IFNDEF ENG}
  txtCppObj_er_NoSetDll = 'Не задана внешняя DLL';


{$ELSE}
  txtCppObj_er_NoSetDll = 'External DLL not set';

{$ENDIF}

implementation

end.
