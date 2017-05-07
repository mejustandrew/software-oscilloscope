#pragma once
#include "IDataProvider.h"
#include "SignalGenerator.h"

class CustomDataProvider : public IDataProvider
{
	SignalGenerator * signalGenerator;

public:
	CustomDataProvider(SignalGenerator * signalGenerator);
	void ChangeSignalGenerator(SignalGenerator * signalGenerator);
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest);
};