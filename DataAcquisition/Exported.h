#include"IDataRequest.h"
#include"IDataResponse.h"


extern "C" _declspec(dllexport) IDataResponse* GetSignalLeftSamples(IDataRequest*request);
extern "C" _declspec(dllexport) IDataResponse* GetSpectrumLeftSamples(int numberOfSamples);//these are whitout treshold
extern "C" _declspec(dllexport) IDataResponse* GetSignalRightSamples(IDataRequest*request);
extern "C" _declspec(dllexport) IDataResponse* GetSpectrumRightSamples(int numberOfSamples);//these are whitout treshold
extern "C" _declspec(dllexport) double Get_sample_rate();
extern "C" _declspec(dllexport) bool Initialize();