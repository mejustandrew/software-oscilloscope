#pragma once
#include"IDataResponse.h"

class ISampleBufferProvider
{
public:
	virtual  IDataResponse*GetSignalLeftSamples(int numberOfSamples, float threshold) = 0;
	virtual IDataResponse* GetSignalRightSamples(int numberOfSamples, float threshold) = 0;
	virtual IDataResponse* GetSpectrumLeftSamples(int numberOfSamples) = 0;
	virtual IDataResponse* GetSpectrumRightSamples(int numberOfSamples) = 0;
	virtual void SetLeftSlope(bool positive) = 0;
	virtual void SetRightSlope(bool positive) = 0;
};