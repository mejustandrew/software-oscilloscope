#pragma once
#include"IDataRequest.h"
#include"DataContainer.h"

class IDualChannelDataProvider
{
protected:
	DataContainer* container;

public:
	IDualChannelDataProvider();
	~IDualChannelDataProvider();
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest) = 0;
	virtual void SetLeftSlope(bool positive) = 0;
	virtual void SetRightSlope(bool positive) = 0;
};