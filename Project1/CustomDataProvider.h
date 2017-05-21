#pragma once
#include "IDataProvider.h"
#include "SignalGenerator.h"

class CustomDataProvider : public IDataProvider
{
	SignalGenerator * leftChannelGenerator;
	SignalGenerator * rightChannelGenerator;

public:
	CustomDataProvider(SignalGenerator * leftChannelGenerator, SignalGenerator * rightChannelGenerator);
	void ChangeLeftChannelGenerator(SignalGenerator * signalGenerator);
	void ChangeRightChannelGenerator(SignalGenerator * signalGenerator);
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest);
};