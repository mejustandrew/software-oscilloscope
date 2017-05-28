#pragma once
#include "CircularBuffer.h"
#include "IDataResponse.h"

class _declspec(dllexport) ResponseBuffer : IDataResponse
{
	int desiredSize;
	int accessPosition;
	CircularBuffer * circularBuffer;
	bool isPositiveSlope;

	int GetPositionOverTreshold(float threshold);
public:
	ResponseBuffer();
	ResponseBuffer(int bufferSize);
	~ResponseBuffer();
	virtual int size() override;
	virtual double operator[] (int index) override;
	virtual void Destroy() override;
	void AddValue(float value);
	IDataResponse * GetBufferWithLoopSize(int numberOfSamples);
	IDataResponse * GetBufferWithLoopSize(int numberOfSamples, float threshold);
	void SetSlope(bool positive);
};