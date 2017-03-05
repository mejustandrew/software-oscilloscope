#pragma once
#include "BuffersManager.h"

class BufferManagerSingleton
{
	static BuffersManager * bufferManager;
	static BuffersManager * GetInitialisedBuffersManager();
public:
	static ISampleBufferProvider * GetSampleBufferProvider();
	static ISamplesHolder * GetSamplesHolder();
};