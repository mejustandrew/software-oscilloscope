#include"IDataRequest.h"
#include"IDataResponse.h"


extern "C" _declspec(dllexport) IDataResponse* GetSignalLeftSamples(IDataRequest*request);
extern "C" _declspec(dllexport) IDataResponse* GetSpectrumLeftSamples(IDataRequest*request);//these are whitout treshold
extern "C" _declspec(dllexport) IDataResponse* GetSignalRightSamples(IDataRequest*request);
extern "C" _declspec(dllexport) IDataResponse* GetSpectrumRightSamples(IDataRequest*request);//these are whitout treshold
extern "C" _declspec(dllexport) double Get_sample_rate();
extern "C" _declspec(dllexport) bool Initialize();