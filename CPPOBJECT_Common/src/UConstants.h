#pragma once

#include <string>

#ifdef _WIN64
#define NATIVEINT __int64
#else
#define NATIVEINT int
#endif

/** @enum EBlockTypes 
/** @brief Типы блоков (для сортировки, частотного анализа, синтеза) */
enum EBlockTypes {
  t_none = 0, ///< @brief Сервисный блок, в расчете не участвует
  t_src = 1,  ///< @brief Блок-источник сигнала
  t_fun = 2,  ///< @brief Функциональный блок
  t_dst = 3,  ///< @brief Блок-приемник информации
  t_del = 4,  ///< @brief Блоки запаздывания
  t_ext = 5,  ///< @brief Блоки-экстраполяторы
  t_der = 6,  ///< @brief Блоки-производные
  t_imp = 7,  ///< @brief Блоки-импортеры данных
  t_exp = 8   ///< @brief Блоки-экспортеры данных
};

/** @enum EActionInfoFunc 
  * Флаги вызовов информационной функции блока */
enum EActionInfoFunc {
  i_GetBlockType = 1,             ///< @brief Получить тип блока (источник, динамический и т.д) - это битовая маска !!!
  i_GetDifCount = 2,              ///< @brief Получить число дифференциальных переменных
  i_GetAlgCount = 4,              ///< @brief Получить число алгебраических переменных
  i_GetCount = 5,                 ///< @brief Получить размерности входов\выходов
  i_GetInit = 6,                  ///< @brief Получить флаг зависимости выходов от входов
  i_GetPropErr = 7,               ///< @brief Проверка правильности задания параметров блока (перед сортировкой)
  i_HaveSpetialEditor = 8,        ///< @brief Флаг - run-объект имеет специализированный редактор блока (вызывается при проверке run-объекта и может использоваться для начальных действий со свойствами)
  i_GetPostSection = 9,           ///< @brief Флаг - блоку нужна пост-секция для выполнения run-функции
  i_ReconnectPorts = 10,          ///< @brief Флаг - действия выполняемые до сортировки для переназначения портов блока
  i_GetSyncPostSection = 11,      ///< @brief Флаг - блоку нужна секция, выполняемая последовательно при синхронном получении данных
  i_GetDisCount = 12,             ///< @brief Получить к-во переменных для дискретных блоков
  i_BeforeEditBlock = 13,         ///< @brief Вызов перед открытием штатного редактора блока
  i_CheckCanClose = 14,           ///< @brief Вызов для проверки нужно ли закрывать проект при изменении блока
  i_GetCustomInfoStageCount = 15, ///< @brief Запрос к-ва дополнительных кастомных стадий инициализации блока
  i_CustomInfoFuncStage = 16      ///< @brief Вызов дополнительной стадии информационной функции блока
};

/** @enum EDataType
  * @brief Идентификаторы типов данных - базовые */
enum EDataType {
  dtDouble = 0,        ///< @brief Data = ^Double
  dtInteger = 1,       ///< @brief Data = ^integer
  dtBool = 2,          ///< @brief Data = ^boolean
  dtColor = 3,         ///< @brief Data = ^TColor
  dtString = 4,        ///< @brief Data = ^string
  dtDoubleArray = 5,   ///< @brief Data =  TExtArray (возможно временно) ***
  dtBitmap = 6,        ///< @brief Data =  TBitmap
  dtFont = 7,          ///< @brief Data =  TMyFont
  dtText = 8,          ///< @brief Data = ^string
  dtPenStyle = 9,      ///< @brief Data = ^TPenStyle
  dtBrushStyle = 10,   ///< @brief Data = ^TBrushStyle
  dtFloatFormat = 11,  ///< @brief Data = ^TFloatFormat
  dtIntArray = 12,     ///< @brief Data =  TIntArray (возможно временно) ***
  dtMatrix = 13,       ///< @brief Data =  TExtArray2
  dtPoint = 14,        ///< @brief Data = ^TMyPoint
  dtEnum = 15,         ///< @brief Data = ^TEnum
  dtFileName = 16,     ///< @brief Data = ^string
  dtDataBaseItem = 17, ///< @brief Data = ^string  - путь файла в базе данных
  dtStream = 18,       ///< @brief Data =  TStream - произвольные данные из файла (звук, видео и т.д.)
  dtComposite = 19,    ///< @brief Data =  TList   - составной тип данных
  dtMultiSelect = 20,  ///< @brief Data =  TMultiSelect - список выбора
  dtComplex = 21,      ///< @brief Data =  TComplex
  dtCompArray = 22,    ///< @brief Data =  TCompArray
  dtCompMatrix = 23,   ///< @brief Data =  TCompMatrix
  dtExternal = 24,     ///< @brief Внешний зарегистрированный тип данных
  dtDiscreteBool = 25, ///< @brief Data = ^boolean - все операции присваивания и переноса выполняются при помощи оператора ИЛИ
   //----- дополнительные - внутренние -----
  dtPointArray = 26,   ///< @brief Data = ^TPointArray
  dtPrimitiv = 27,     ///< @brief Data =  TPrimitiv
  dtStrings = 28,      ///< @brief Data =  TStrings
  dtCFName = 29,       ///< @brief Data = ^string
  dtPString = 30,      ///< @brief Data = ^Pstream (^^string)
  dtGraphics = 31      ///< @brief Data =  TGContainer
};

/** @enum EWorkState 
  * @brief Флаги вызова run-функции блока*/
enum EWorkState
{
  f_InitState = 1,      ///< @brief Запись начальных состояний
  f_UpdateOuts = 2,     ///< @brief Обновить выходы на предварительном шаге
  f_GoodStep = 3,       ///< @brief Обновить выходы на "хорошем" шаге
  f_GetDeri = 4,        ///< @brief Вычислить значения правых частей дифференциальных уравнений
  f_GetAlgFun = 5,      ///< @brief Вычислить значения правых частей алгебраических уравнений
  f_SetState = 6,       ///< @brief Вычислить значения дискретных переменных состояния (после шага интегрирования)
  f_UpdateProps = 7,    ///< @brief Обновить список параметров (с учётом флага изменяемости)
  f_UpdateJacoby = 9,   ///< @brief Обновить выходы блока при расчёте матрицы Якоби (эквивалент f_UpdateOuts с дополнительным вызовом обновления дискретных состояний)
  f_RestoreOuts = 10,   ///< @brief Обновить выходы после рестарта (только если очень надо, т.к. выходы всё равно будут запоминаться)
  f_SetAlgOut = 11,     ///< @brief Выставить выходы блока, содержащих алгебраические переменные
  f_InitAlgState = 12,  ///< @brief Выставить начальное приближение для алгебраические переменных
  f_Stop = 13,          ///< @brief Вызывается при остановке расчёта (конец моделирования)
  f_InitObjects = 14,   ///< @brief Инициализация объектов, массивов и т.д. (сразу после сортировки) (начало моделирования)
  f_EndTimeTask = 15    ///< @brief Вызывается по окончании выполнения задачи (для проверки оптимизации и т.п.)
};

/** @enum ELogLevel 
  * @brief Уровни предупреждения */
enum ELogLevel {
  LLInfo,         //Просто информация
  LLError,        //Сообщения об ошибке
  LLWarning,      //Предупреждение
  LLHidden        //Скрытое сообщение
};

/** @enum EFunctionResult
  * Возможные результаты функций */
enum EFunctionResult {
  r_Success = 0, ///< @brief Нет ошибки
  r_Fail = 1     ///< @brief Возникла ошибка
};


/** @brief Идентификатор типа данных */
typedef unsigned char TDataType;

/** @brief Данные о точке */
typedef struct { double X; double Y; } TMyPoint;

/** @brief Данные для изменения порта */
typedef struct {
  int m_count;  // количество
  int m_mode;   // режим по умолчанию
  int m_type;   // тип связи по умолчанию
  unsigned char m_side; //  расположение порта по умолчанию
} TPortData;

/** @brief Данные для условного изменения порта */
typedef struct {
  int m_count;          //  количество портов
  int m_mode;           //  режим портов
  int m_type;           //  тип связи портов
  unsigned char m_side; //  расположение порта по умолчанию
  char m_name[128];     //  шаблон имени портов
  int m_portVariant;    //  вариант порта
} TCondPortData;

/** @brief тип для хранения лог-информации */
typedef struct { std::string m_text; int m_level; } TLoggerData;

constexpr int MAX_ER_LENGTH = 1024; ///< @brief Максимальный размер строки ошибки
