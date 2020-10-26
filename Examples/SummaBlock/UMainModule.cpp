#include <vector>

#include "UMainModule.h"
#include "BlockInterface.h"

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
