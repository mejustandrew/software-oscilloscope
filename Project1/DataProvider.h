#pragma once
#include"IDataRequest.h"
#include"DataContainer.h"

class DataProvider
{
	DataContainer* container;
public:
	DataProvider();
	~DataProvider();

	DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest);
};