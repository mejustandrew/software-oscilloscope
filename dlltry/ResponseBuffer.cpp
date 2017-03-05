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
	return circularBuffer->GetNumberOfAvaiableValues() >= numberOfSamples ? this : nullptr;
}

IDataResponse * ResponseBuffer::GetBufferWithLoopSize(int numberOfSamples, float threshold)
{
	int avaiableSamples = circularBuffer->GetNumberOfAvaiableValues();
	if (avaiableSamples < numberOfSamples)return nullptr;

	int foundPosition = GetPositionOverTreshold(threshold);
	if (foundPosition + numberOfSamples < avaiableSamples)
	{
		accessPosition = foundPosition;
		return this;
	}
	return nullptr;
}

int ResponseBuffer::GetPositionOverTreshold(float threshold)
{
	for (int i = 0; i < circularBuffer->GetNumberOfAvaiableValues(); i++)
	{
		if ((*circularBuffer)[i] < threshold && threshold < (*circularBuffer)[i + 1]) return i + 1;
	}
	return -1;
}
