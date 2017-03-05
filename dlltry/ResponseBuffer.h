#pragma once
#include "CircularBuffer.h"
#include "IDataResponse.h"

class ResponseBuffer : IDataResponse
{
	int desiredSize;
	int accessPosition;
	CircularBuffer * circularBuffer;

	int GetPositionOverTreshold(float threshold);
public:
	ResponseBuffer();
	~ResponseBuffer();
	virtual int size() override;
	virtual double operator[] (int index) override;
	virtual void Destroy() override;
	void AddValue(float value);
	IDataResponse * GetBufferWithLoopSize(int numberOfSamples);
	IDataResponse * GetBufferWithLoopSize(int numberOfSamples, float threshold);
};