#include <vector>
#include <string.h>
#include <stdexcept>

#include "UMainModule.h"
#include "BlockInterface.h"
#include "ULogger.h"

using namespace cppobj;
static std::vector<BlockInterface*> CppObjectHandles_vec; ///< @brief ����� �� ����� ������������� ������

int createModule(void * object)
{
	int index = static_cast<int>(CppObjectHandles_vec.size());
	BlockInterface* process = CreateBlockObject(object);
	if (!process) {
		return -1;
	}
	CppObjectHandles_vec.push_back(process);
	return index;
}

void destroyModule(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface * process = CppObjectHandles_vec[index];
		delete process;
		CppObjectHandles_vec[index] = nullptr;
		ULogger::reset();
	}
}

NATIVEINT infoFunc(int index, int Action, NATIVEINT aParameter)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->infoFunc(Action, aParameter);
	}
	return -1;
}

NATIVEINT getParamID(int index, const char * ParamName, TDataType& DataType, bool& IsConst)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		 BlockInterface* process = CppObjectHandles_vec[index];
		 return process->getParamID(ParamName, DataType, IsConst);
	}
	return -1;
}

int getMultiselectQty(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getMultiselectQty();
	}
	return 0; // ���� ���� ������ - ������ 0, ���� �� �������� �� ������
}

void addMultiselect(int index, void* multiselect)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		process->addMultiselect(multiselect);
	}
}

void* getMultiselect(int index, int number)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getMultiselect(number);
	}
	return nullptr; // ���� ���� ������ - ������ 0, ���� �� �������� �� ������
}

void editFunc(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		process->editFunc();
	}
}

int getPortDataQty(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getPortDataQty();
	}
	return 0; // ���� ���� ������ - ������ 0, ���� �� �������� �� ������
}

int getCondPortDataQty(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getCondPortDataQty();
	}
	return 0; // ���� ���� ������ - ������ 0, ���� �� �������� �� ������
}

TPortData getPortData(int index, int number)
{
	try {
		if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
			BlockInterface* process = CppObjectHandles_vec[index];
			return process->getPortData(number);
		} else {
			throw(std::out_of_range("Index of module is failure"));
		}
	}
	catch (std::exception& e) {
		ULogger::instance()->error(e.what());
		TPortData portData;
		portData.m_mode = -1; // �������� ������
		return portData;
	}
}

TCondPortData getCondPortData(int index, int number)
{
	try {
		if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
			BlockInterface* process = CppObjectHandles_vec[index];
			return process->getCondPortData(number);
		} else {
			throw(std::out_of_range("Index of module is failure"));
		}
	}
	catch (std::exception& e) {
		ULogger::instance()->error(e.what());
		TCondPortData condPortData;
		condPortData.m_mode = -1; // �������� ������
		return condPortData;
	}
}

NATIVEINT runFunc(int index, double& at, double& h, int action)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->run(at, h, static_cast<EWorkState>(action));
	}
	return -1;
}

int lastError(int index, char* error, int & code)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		TLoggerData data;
		int retCode = ULogger::instance()->last(data);
		if (retCode >= 0) { // ������ ���� ���� ������
			strcpy_s(error, MAX_ER_LENGTH, data.m_text.c_str());
			code = data.m_level;
			return retCode;
		}
	}
	return -1;
}
