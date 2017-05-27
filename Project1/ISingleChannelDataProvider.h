#pragma once
#include"IDataRequest.h"
#include"../dlltry/IDataResponse.h"

class ISingleChannelDataProvider
{
protected:
	IDataResponse *ResponseData;

public:
	ISingleChannelDataProvider();
	virtual ~ISingleChannelDataProvider();
	virtual IDataResponse* GetNewData(int numberOfSamples) = 0;
};