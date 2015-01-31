
class IDataRequest;
class IDataResponse;

extern "C" _declspec(dllimport) IDataResponse* GetSignalSamples (IDataRequest * requestData);

extern "C" _declspec(dllimport) IDataResponse* GetSpectrumSamples(IDataRequest*request);