#pragma once

#include <string>

#ifdef _WIN64
#define NATIVEINT __int64
#else
#define NATIVEINT int
#endif

/** @enum EBlockTypes 
/** @brief ���� ������ (��� ����������, ���������� �������, �������) */
enum EBlockTypes {
  t_none = 0, ///< @brief ��������� ����, � ������� �� ���������
  t_src = 1,  ///< @brief ����-�������� �������
  t_fun = 2,  ///< @brief �������������� ����
  t_dst = 3,  ///< @brief ����-�������� ����������
  t_del = 4,  ///< @brief ����� ������������
  t_ext = 5,  ///< @brief �����-��������������
  t_der = 6,  ///< @brief �����-�����������
  t_imp = 7,  ///< @brief �����-��������� ������
  t_exp = 8   ///< @brief �����-���������� ������
};

/** @enum EActionInfoFunc 
  * ����� ������� �������������� ������� ����� */
enum EActionInfoFunc {
  i_GetBlockType = 1,             ///< @brief �������� ��� ����� (��������, ������������ � �.�) - ��� ������� ����� !!!
  i_GetDifCount = 2,              ///< @brief �������� ����� ���������������� ����������
  i_GetAlgCount = 4,              ///< @brief �������� ����� �������������� ����������
  i_GetCount = 5,                 ///< @brief �������� ����������� ������\�������
  i_GetInit = 6,                  ///< @brief �������� ���� ����������� ������� �� ������
  i_GetPropErr = 7,               ///< @brief �������� ������������ ������� ���������� ����� (����� �����������)
  i_HaveSpetialEditor = 8,        ///< @brief ���� - run-������ ����� ������������������ �������� ����� (���������� ��� �������� run-������� � ����� �������������� ��� ��������� �������� �� ����������)
  i_GetPostSection = 9,           ///< @brief ���� - ����� ����� ����-������ ��� ���������� run-�������
  i_ReconnectPorts = 10,          ///< @brief ���� - �������� ����������� �� ���������� ��� �������������� ������ �����
  i_GetSyncPostSection = 11,      ///< @brief ���� - ����� ����� ������, ����������� ��������������� ��� ���������� ��������� ������
  i_GetDisCount = 12,             ///< @brief �������� �-�� ���������� ��� ���������� ������
  i_BeforeEditBlock = 13,         ///< @brief ����� ����� ��������� �������� ��������� �����
  i_CheckCanClose = 14,           ///< @brief ����� ��� �������� ����� �� ��������� ������ ��� ��������� �����
  i_GetCustomInfoStageCount = 15, ///< @brief ������ �-�� �������������� ��������� ������ ������������� �����
  i_CustomInfoFuncStage = 16      ///< @brief ����� �������������� ������ �������������� ������� �����
};

/** @enum EDataType
  * @brief �������������� ����� ������ - ������� */
enum EDataType {
  dtDouble = 0,        ///< @brief Data = ^Double
  dtInteger = 1,       ///< @brief Data = ^integer
  dtBool = 2,          ///< @brief Data = ^boolean
  dtColor = 3,         ///< @brief Data = ^TColor
  dtString = 4,        ///< @brief Data = ^string
  dtDoubleArray = 5,   ///< @brief Data =  TExtArray (�������� ��������) ***
  dtBitmap = 6,        ///< @brief Data =  TBitmap
  dtFont = 7,          ///< @brief Data =  TMyFont
  dtText = 8,          ///< @brief Data = ^string
  dtPenStyle = 9,      ///< @brief Data = ^TPenStyle
  dtBrushStyle = 10,   ///< @brief Data = ^TBrushStyle
  dtFloatFormat = 11,  ///< @brief Data = ^TFloatFormat
  dtIntArray = 12,     ///< @brief Data =  TIntArray (�������� ��������) ***
  dtMatrix = 13,       ///< @brief Data =  TExtArray2
  dtPoint = 14,        ///< @brief Data = ^TMyPoint
  dtEnum = 15,         ///< @brief Data = ^TEnum
  dtFileName = 16,     ///< @brief Data = ^string
  dtDataBaseItem = 17, ///< @brief Data = ^string  - ���� ����� � ���� ������
  dtStream = 18,       ///< @brief Data =  TStream - ������������ ������ �� ����� (����, ����� � �.�.)
  dtComposite = 19,    ///< @brief Data =  TList   - ��������� ��� ������
  dtMultiSelect = 20,  ///< @brief Data =  TMultiSelect - ������ ������
  dtComplex = 21,      ///< @brief Data =  TComplex
  dtCompArray = 22,    ///< @brief Data =  TCompArray
  dtCompMatrix = 23,   ///< @brief Data =  TCompMatrix
  dtExternal = 24,     ///< @brief ������� ������������������ ��� ������
  dtDiscreteBool = 25, ///< @brief Data = ^boolean - ��� �������� ������������ � �������� ����������� ��� ������ ��������� ���
   //----- �������������� - ���������� -----
  dtPointArray = 26,   ///< @brief Data = ^TPointArray
  dtPrimitiv = 27,     ///< @brief Data =  TPrimitiv
  dtStrings = 28,      ///< @brief Data =  TStrings
  dtCFName = 29,       ///< @brief Data = ^string
  dtPString = 30,      ///< @brief Data = ^Pstream (^^string)
  dtGraphics = 31      ///< @brief Data =  TGContainer
};

/** @enum EWorkState 
  * @brief ����� ������ run-������� �����*/
enum EWorkState
{
  f_InitState = 1,      ///< @brief ������ ��������� ���������
  f_UpdateOuts = 2,     ///< @brief �������� ������ �� ��������������� ����
  f_GoodStep = 3,       ///< @brief �������� ������ �� "�������" ����
  f_GetDeri = 4,        ///< @brief ��������� �������� ������ ������ ���������������� ���������
  f_GetAlgFun = 5,      ///< @brief ��������� �������� ������ ������ �������������� ���������
  f_SetState = 6,       ///< @brief ��������� �������� ���������� ���������� ��������� (����� ���� ��������������)
  f_UpdateProps = 7,    ///< @brief �������� ������ ���������� (� ������ ����� ������������)
  f_UpdateJacoby = 9,   ///< @brief �������� ������ ����� ��� ������� ������� ����� (���������� f_UpdateOuts � �������������� ������� ���������� ���������� ���������)
  f_RestoreOuts = 10,   ///< @brief �������� ������ ����� �������� (������ ���� ����� ����, �.�. ������ �� ����� ����� ������������)
  f_SetAlgOut = 11,     ///< @brief ��������� ������ �����, ���������� �������������� ����������
  f_InitAlgState = 12,  ///< @brief ��������� ��������� ����������� ��� �������������� ����������
  f_Stop = 13,          ///< @brief ���������� ��� ��������� ������� (����� �������������)
  f_InitObjects = 14,   ///< @brief ������������� ��������, �������� � �.�. (����� ����� ����������) (������ �������������)
  f_EndTimeTask = 15    ///< @brief ���������� �� ��������� ���������� ������ (��� �������� ����������� � �.�.)
};

/** @enum ELogLevel 
  * @brief ������ �������������� */
enum ELogLevel {
  LLInfo,         //������ ����������
  LLError,        //��������� �� ������
  LLWarning,      //��������������
  LLHidden        //������� ���������
};

/** @enum EFunctionResult
  * ��������� ���������� ������� */
enum EFunctionResult {
  r_Success = 0, ///< @brief ��� ������
  r_Fail = 1     ///< @brief �������� ������
};


/** @brief ������������� ���� ������ */
typedef unsigned char TDataType;

/** @brief ������ � ����� */
typedef struct { double X; double Y; } TMyPoint;

/** @brief ������ ��� ��������� ����� */
typedef struct {
  int m_count;  // ����������
  int m_mode;   // ����� �� ���������
  int m_type;   // ��� ����� �� ���������
  unsigned char m_side; //  ������������ ����� �� ���������
} TPortData;

/** @brief ������ ��� ��������� ��������� ����� */
typedef struct {
  int m_count;          //  ���������� ������
  int m_mode;           //  ����� ������
  int m_type;           //  ��� ����� ������
  unsigned char m_side; //  ������������ ����� �� ���������
  char m_name[128];     //  ������ ����� ������
  int m_portVariant;    //  ������� �����
} TCondPortData;

typedef struct {
  NATIVEINT m_main;
  int m_length;
  int m_reserve;
  NATIVEINT m_array;
} SControlData;

/** @brief ��� ��� �������� ���-���������� */
typedef struct { std::string m_text; int m_level; } TLoggerData;

constexpr int MAX_ER_LENGTH = 1024; ///< @brief ������������ ������ ������ ������
