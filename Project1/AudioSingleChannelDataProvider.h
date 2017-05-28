#pragma once
#include"ISingleChannelDataProvider.h"

class AudioSingleChannelDataProvider : public ISingleChannelDataProvider
{
	IDataResponse* (*GetSamples)(int numberOfSamples);
public:
	void SetDataSourceFuntion(IDataResponse* (*GetSamples)(int numberOfSamples));
	virtual IDataResponse* GetNewData(int numberOfSamples);
	AudioSingleChannelDataProvider(IDataResponse* (*GetSamples)(int numberOfSamples));
};