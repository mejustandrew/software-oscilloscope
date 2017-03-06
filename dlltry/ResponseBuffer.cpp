#include "ResponseBuffer.h"

ResponseBuffer::ResponseBuffer()
{
	circularBuffer = new CircularBuffer;
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
	for (int i = 1; i < circularBuffer->GetNumberOfAvaiableValues() - 2; i++)
	{
		if ((*circularBuffer)[i - 1] < threshold && (*circularBuffer)[i]) return i;
	}
	return -1;
}
