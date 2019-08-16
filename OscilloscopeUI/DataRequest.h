#include"IDataRequest.h"

class DataRequest: public IDataRequest
{
double TimeBase;
double Treshold;
public:	
	DataRequest(double time_base,double treshold):TimeBase(time_base),Treshold(treshold)
	{
	}
	double GetTimeBase();
	double GetTreshold();
};