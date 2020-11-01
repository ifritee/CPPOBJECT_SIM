#include <vector>

#include "UMainModule.h"
#include "BlockInterface.h"
#include "ULogger.h"

using namespace cppobj;
static std::vector<BlockInterface*> CppObjectHandles_vec; ///< @brief Набор со всеми дескрипторами блоков

int createModule()
{
	int index = static_cast<int>(CppObjectHandles_vec.size());
	BlockInterface* process = CreateBlockObject();
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
	return 0; // Даже если ошибка - вернем 0, чтоб не вылететь за память
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
	return nullptr; // Даже если ошибка - вернем 0, чтоб не вылететь за память
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
	return 0; // Даже если ошибка - вернем 0, чтоб не вылететь за память
}

int getCondPortDataQty(int index)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getCondPortDataQty();
	}
	return 0; // Даже если ошибка - вернем 0, чтоб не вылететь за память
}

TPortData getPortData(int index, int number)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getPortData(number);
	}
	TPortData portData;
	portData.m_mode = -1; // Условная ошибка
	return portData; // Даже если ошибка - вернем 0, чтоб не вылететь за память
}

TCondPortData getCondPortData(int index, int number)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->getCondPortData(number);
	}
	TCondPortData condPortData;
	condPortData.m_mode = -1; // Условная ошибка
	return condPortData; // Даже если ошибка - вернем 0, чтоб не вылететь за память
}

NATIVEINT runFunc(int index, double& at, double& h, int action)
{
	if (index >= 0 && index < static_cast<int>(CppObjectHandles_vec.size()) && CppObjectHandles_vec[index] != nullptr) {
		BlockInterface* process = CppObjectHandles_vec[index];
		return process->run(at, h, static_cast<EWorkState>(action));
	}
	return -1;
}
