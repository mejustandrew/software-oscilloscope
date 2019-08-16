#pragma once
#include"IDataRequest.h"
#include"../DataAcquisition/IDataResponse.h"

class ISingleChannelDataProvider
{
protected:
	IDataResponse *ResponseData;

public:
	ISingleChannelDataProvider();
	virtual ~ISingleChannelDataProvider();
	virtual IDataResponse* GetNewData(int numberOfSamples) = 0;
};