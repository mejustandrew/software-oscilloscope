#include "CircularBuffer.h"


CircularBuffer::CircularBuffer(int bufferSize) 
{
	this->bufferSize = bufferSize;
	buffer = new float[bufferSize];
	overBuffer = false;
	addingPosition = 0;
}

CircularBuffer::~CircularBuffer()
{
	delete[]buffer;
}

void CircularBuffer::AddValue(float value)
{
	buffer[addingPosition] = value;
	IncrementAddingPosition();
}

void CircularBuffer::IncrementAddingPosition()
{
	addingPosition++;
	if (addingPosition == bufferSize)
	{
		addingPosition = 0;
		overBuffer = true;
	}
}

int CircularBuffer::GetNumberOfAvaiableValues()
{
	return overBuffer ? bufferSize : addingPosition;
}

void CircularBuffer::ResetBuffer()
{
	overBuffer = false;
	addingPosition = 0;
}

double CircularBuffer::operator[](int index)
{
	return overBuffer ? buffer[addingPosition - desiredLoopSize + index] : buffer [index];
}