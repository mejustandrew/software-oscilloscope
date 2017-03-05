#include "BufferManagerSingleton.h"

BuffersManager * BufferManagerSingleton::bufferManager = nullptr;

ISampleBufferProvider * BufferManagerSingleton::GetSampleBufferProvider()
{
	return GetInitialisedBuffersManager();
}

ISamplesHolder * BufferManagerSingleton::GetSamplesHolder()
{
	return GetInitialisedBuffersManager();
}

BuffersManager * BufferManagerSingleton::GetInitialisedBuffersManager()
{
	if (bufferManager = nullptr)
		bufferManager = new BuffersManager;
	return bufferManager;
}