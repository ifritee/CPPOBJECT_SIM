#pragma once

#include <string>

#include "UConstants.h"

#ifdef CPPBLOCK_EXPORTS
#define SUMMABLOCK_API __declspec(dllexport)
#else
#define SUMMABLOCK_API __declspec(dllimport)
#endif // CPPBLOCK_EXPORTS

extern "C" 
{
  /** @brief �������� ������ (���������� ID ������)*/
  SUMMABLOCK_API int createModule();
  /** @brief �������� ������ */
  SUMMABLOCK_API void destroyModule(int);
  /** @brief �������������� �������� ��������� ������ */
  SUMMABLOCK_API NATIVEINT infoFunc(int index, int Action, NATIVEINT aParameter);
  /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
  SUMMABLOCK_API NATIVEINT getParamID(int index, const char * ParamName, TDataType& DataType, bool& IsConst);
  /** @brief ���������� ����������� ��������� �������������� */
  SUMMABLOCK_API int getMultiselectQty(int index);
  /** @brief ���������� ���������� Multiselect */
  SUMMABLOCK_API void addMultiselect(int index, void * multiselect);
  /** @brief ���������� ��������� ������������ ��� nullptr */
  SUMMABLOCK_API void* getMultiselect(int index, int number);
  /** @brief ������� ��� ����������� ��������� ���������� ���������� ����� */
  SUMMABLOCK_API void editFunc(int index);
  /** @brief ���������� ���������� ������ ��� ��������� ����� */
  SUMMABLOCK_API int getPortDataQty(int index);
  /** @brief ���������� ���������� ������ ��� ��������� ��������� ����� */
  SUMMABLOCK_API int getCondPortDataQty(int index);
  /** @brief ���������� ������ ��� ��������� ����� */
  SUMMABLOCK_API TPortData getPortData(int index, int number);
  /** @brief ���������� ������ ��� ��������� ��������� ����� */
  SUMMABLOCK_API TCondPortData getCondPortData(int index, int number);
  /** @brief RUN-������� �����, ���� ���������� �������� > 0 - �� ������ ����� �������� ���������� */
  SUMMABLOCK_API NATIVEINT runFunc(int index, double & at, double & h, int action);
}

