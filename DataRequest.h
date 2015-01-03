#include"IDataRequest.h"

class DataRequest : public IDataRequest
{
	double timebase;
	double treshold;
public:
	DataRequest(double tb,double th):timebase(tb),treshold(th)
	{
	}
	double GetTimeBase();
	double GetTreshold();

};