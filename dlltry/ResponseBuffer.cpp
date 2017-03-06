#include "ResponseBuffer.h"

ResponseBuffer::ResponseBuffer()
{
	circularBuffer = new CircularBuffer;
	accessPosition = 0;
}

ResponseBuffer::ResponseBuffer(int bufferSize)
{
	circularBuffer = new CircularBuffer(bufferSize);
	accessPosition = 0;
}

ResponseBuffer::~ResponseBuffer()
{
	delete circularBuffer;
}

int ResponseBuffer::size()
{
	return desiredSize;
}

double ResponseBuffer::operator[](int index)
{
	return (*circularBuffer)[index + accessPosition];
}

void ResponseBuffer::Destroy()
{
	circularBuffer->ResetBuffer();
	accessPosition = 0;
}

void ResponseBuffer::AddValue(float value)
{
	circularBuffer->AddValue(value);
}

IDataResponse * ResponseBuffer::GetBufferWithLoopSize(int numberOfSamples)
{
	int avaiableSamples = circularBuffer->GetNumberOfAvaiableValues();
	if (avaiableSamples >= numberOfSamples)
	{
		desiredSize = numberOfSamples;
		return this;
	}
	return nullptr;
}

IDataResponse * ResponseBuffer::GetBufferWithLoopSize(int numberOfSamples, float threshold)
{
	int avaiableSamples = circularBuffer->GetNumberOfAvaiableValues();
	if (avaiableSamples < numberOfSamples)return nullptr;

	int foundPosition = GetPositionOverTreshold(threshold);
	if (foundPosition == -1) return nullptr;
	if (foundPosition + numberOfSamples < avaiableSamples)
	{
		accessPosition = foundPosition;
		desiredSize = numberOfSamples;
		return this;
	}
	return nullptr;
}

int ResponseBuffer::GetPositionOverTreshold(float threshold)
{
	float a, b;
	for (int i = 0; i < circularBuffer->GetNumberOfAvaiableValues() - 1; i++)
	{
		a = (*circularBuffer)[i];
		b = (*circularBuffer)[i + 1];
		if (a < threshold && threshold <= b) return i+1;
	}
	return -1;
}
