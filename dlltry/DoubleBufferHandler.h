#pragma once
#include "IDataResponse.h"
#include "ResponseBuffer.h"

class DoubleBufferHandler
{
	ResponseBuffer *responseBuffer1, *responseBuffer2;
	bool isBuffer1Inserting;

	ResponseBuffer* GetInsertingBuffer();
	void SwapBuffers();

public:
	DoubleBufferHandler();
	DoubleBufferHandler(int bufferSize);
	~DoubleBufferHandler();
	void AddValue(float value);
	IDataResponse* GetBufferWithSizeOf(int size);
	IDataResponse* GetBufferWithSizeOf(int size, float treshold);
};