#pragma once
#include"IDataRequest.h"
#include"DataContainer.h"

class IDataProvider
{
protected:
	DataContainer* container;

public:
	IDataProvider();
	~IDataProvider();
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest) = 0;
};