#pragma once
#pragma once
#include "ISingleChannelDataProvider.h"
#include "SignalGenerator.h"

class CustomSingleChannelDataProvider : public ISingleChannelDataProvider
{
	SignalGenerator * signalGenerator;

public:
	CustomSingleChannelDataProvider(SignalGenerator * signalGenerator);
	void ChangeSignalGenerator(SignalGenerator * signalGenerator);
	virtual IDataResponse* GetNewData(int numberOfSamples);
};