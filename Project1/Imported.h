
class IDataRequest;
class IDataResponse;

extern "C" _declspec(dllimport) IDataResponse* GetSignalSamples (IDataRequest * requestData);
extern "C" _declspec(dllimport) double Get_sample_rate();
extern "C" _declspec(dllimport) IDataResponse* GetSpectrumSamples(IDataRequest*request);
extern "C" _declspec(dllimport) bool Initialize();