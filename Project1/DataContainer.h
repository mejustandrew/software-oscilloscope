#pragma once
#include "../dlltry/IDataResponse.h"

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
