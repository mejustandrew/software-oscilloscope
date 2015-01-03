#include"IDataRequest.h"
#include"IDataResponse.h"

extern "C" _declspec(dllexport) void Initialize();
extern "C" _declspec(dllexport) IDataResponse* GetSignalSamples(IDataRequest*request);
