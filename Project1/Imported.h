
class IDataRequest;
class IDataResponse;


extern "C" _declspec(dllimport) double Get_sample_rate();
extern "C" _declspec(dllimport) IDataResponse* GetSignalLeftSamples(IDataRequest*request);
extern "C" _declspec(dllimport) IDataResponse* GetSpectrumLeftSamples(IDataRequest*request);
extern "C" _declspec(dllimport) IDataResponse* GetSignalRightSamples(IDataRequest*request);
extern "C" _declspec(dllimport) IDataResponse* GetSpectrumRightSamples(IDataRequest*request);
extern "C" _declspec(dllimport) bool Initialize();