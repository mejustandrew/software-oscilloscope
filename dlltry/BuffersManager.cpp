#include "BuffersManager.h"

BuffersManager::BuffersManager()
{
	leftSignalBuffer = new DoubleBufferHandler;
	leftSpectrumBuffer = new DoubleBufferHandler;
	rightSignalBuffer = new DoubleBufferHandler;
	rightSpectrumBuffer = new DoubleBufferHandler;
}

BuffersManager::~BuffersManager()
{
	delete leftSignalBuffer;
	delete leftSpectrumBuffer;
	delete rightSignalBuffer;
	delete rightSpectrumBuffer;
}

void BuffersManager::AddLeftSample(float sample)
{
	leftSignalBuffer->AddValue(sample);
	leftSpectrumBuffer->AddValue(sample);
}

void BuffersManager::AddRightSampele(float sample)
{
	rightSignalBuffer->AddValue(sample);
	rightSpectrumBuffer->AddValue(sample);
}

IDataResponse * BuffersManager::GetSignalLeftSamples(int numberOfSamples, float threshold)
{
	return leftSignalBuffer->GetBufferWithSizeOf(numberOfSamples, threshold);
}

IDataResponse * BuffersManager::GetSignalRightSamples(int numberOfSamples, float threshold)
{
	return rightSignalBuffer->GetBufferWithSizeOf(numberOfSamples, threshold);
}

IDataResponse * BuffersManager::GetSpectrumLeftSamples(int numberOfSamples)
{
	return leftSpectrumBuffer->GetBufferWithSizeOf(numberOfSamples);
}

IDataResponse * BuffersManager::GetSpectrumRightSamples(int numberOfSamples)
{
	return rightSpectrumBuffer->GetBufferWithSizeOf(numberOfSamples);
}
