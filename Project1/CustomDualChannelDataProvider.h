#pragma once
#include "IDualChannelDataProvider.h"
#include "SignalGenerator.h"

class CustomDualChannelDataProvider : public IDualChannelDataProvider
{
	SignalGenerator * leftChannelGenerator;
	SignalGenerator * rightChannelGenerator;

public:
	CustomDualChannelDataProvider(SignalGenerator * leftChannelGenerator, SignalGenerator * rightChannelGenerator);
	void ChangeLeftChannelGenerator(SignalGenerator * signalGenerator);
	void ChangeRightChannelGenerator(SignalGenerator * signalGenerator);
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest);
};