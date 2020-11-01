#pragma once

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

/** @brief Идентификатор типа данных */
typedef unsigned char TDataType;

/** @brief Данные о точке */
typedef struct { double X; double Y; } TMyPoint;
