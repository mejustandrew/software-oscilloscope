#include"IDataRequest.h"
#include"IDataResponse.h"


extern "C" _declspec(dllexport) IDataResponse* GetSignalSamples(IDataRequest*request);
extern "C" _declspec(dllexport) IDataResponse* GetSpectrumSamples(IDataRequest*request);//these are whitout treshold
extern "C" _declspec(dllexport) double Get_sample_rate();