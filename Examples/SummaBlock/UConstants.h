#pragma once

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


