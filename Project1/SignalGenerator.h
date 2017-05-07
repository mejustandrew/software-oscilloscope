#pragma once
#include "../dlltry/ResponseBuffer.h"
#include "IDataRequest.h"

class SignalGenerator
{
protected:
	ResponseBuffer *response;
	double sampleRate;
	int responseSize;

public:
	SignalGenerator(double sampleRate) : sampleRate(sampleRate)
	{
		responseSize = 64000;
		response = new ResponseBuffer(responseSize);
	}
	virtual IDataResponse * GetSignal(IDataRequest * request) = 0;
};