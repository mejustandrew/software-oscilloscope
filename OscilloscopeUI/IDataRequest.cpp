#include"IDataRequest.h"
#include"WorkingFrame.h"
class DataRequest: public IDataRequest
{
	DataRequest(WorkingFrame *primit):frame(primit)
	{
	}

	 WorkingFrame *frame;
public:	

	double GetTimeBase(){ return	frame->GetTimeBase(); }
	double GetTreshold(){ return	frame->GetTreshold(); }

};