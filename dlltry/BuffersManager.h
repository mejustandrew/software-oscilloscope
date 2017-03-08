#pragma once
#include "ISampleBuffersProvider.h"
#include "ISamplesHolder.h"
#include "DoubleBufferHandler.h"

class BuffersManager : public ISampleBufferProvider, public ISamplesHolder
{
	DoubleBufferHandler * leftSignalBuffer;
	DoubleBufferHandler * rightSignalBuffer;
	DoubleBufferHandler * leftSpectrumBuffer;
	DoubleBufferHandler * rightSpectrumBuffer;

public:
	BuffersManager();
	~BuffersManager();
	virtual void AddLeftSample(float sample) override;
	virtual void AddRightSampele(float sample) override;
	virtual IDataResponse* GetSignalLeftSamples(int numberOfSamples, float threshold) override;
	virtual IDataResponse* GetSignalRightSamples(int numberOfSamples, float threshold) override;
	virtual IDataResponse* GetSpectrumLeftSamples(int numberOfSamples) override;
	virtual IDataResponse* GetSpectrumRightSamples(int numberOfSamples) override;
};