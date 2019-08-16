#pragma once
#include "../DataAcquisition/IDataResponse.h"

struct DataContainer
{
	IDataResponse *LeftChannelData;
	IDataResponse *RightChannelData;
	DataContainer()
	{
		LeftChannelData = nullptr;
		RightChannelData = nullptr;
	}
};
