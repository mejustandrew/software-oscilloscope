#include "ResponseBuffer.h"

ResponseBuffer::ResponseBuffer()
{
	circularBuffer = new CircularBuffer;
	accessPosition = 0;
	isPositiveSlope = true;
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

void ResponseBuffer::SetSlope(bool positive)
{
	isPositiveSlope = positive;
}

int ResponseBuffer::GetPositionOverTreshold(float threshold)
{
	if (isPositiveSlope)
	{
		for (int i = 0; i < circularBuffer->GetNumberOfAvaiableValues(); i++)
		{
			if ((*circularBuffer)[i] < threshold && threshold <= (*circularBuffer)[i + 1]) return i + 1;
		}
	}
	else
	{
		for (int i = 0; i < circularBuffer->GetNumberOfAvaiableValues(); i++)
		{
			if ((*circularBuffer)[i] > threshold && threshold >= (*circularBuffer)[i + 1]) return i + 1;
		}
	}
	return -1;
}
