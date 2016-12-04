
class IDataRequest;
class IDataResponse;


extern "C" _declspec(dllimport) double Get_sample_rate();
extern "C" _declspec(dllimport) IDataResponse* GetSignalLeftSamples(IDataRequest*request);
extern "C" _declspec(dllimport) IDataResponse* GetSpectrumLeftSamples(int numberOfSamples);
extern "C" _declspec(dllimport) IDataResponse* GetSignalRightSamples(IDataRequest*request);
extern "C" _declspec(dllimport) IDataResponse* GetSpectrumRightSamples(int numberOfSample);
extern "C" _declspec(dllimport) bool Initialize();