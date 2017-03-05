#pragma once
#include "IDataResponse.h"
#include "ResponseBuffer.h"

class DoubleBufferHandler
{
	ResponseBuffer *responseBuffer1, *responseBuffer2;
	bool isBuffer1Inserting;

	ResponseBuffer* GetInsertingBuffer();

public:
	DoubleBufferHandler();
	~DoubleBufferHandler();
	void AddValue(float value);
	IDataResponse* GetBufferWithSizeOf(int size);
	IDataResponse* GetBufferWithSizeOf(int size, float treshold);
};