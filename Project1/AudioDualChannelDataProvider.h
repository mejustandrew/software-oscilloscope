#pragma once
#include"IDualChannelDataProvider.h"

class AudioDualChannelDataProvider : public IDualChannelDataProvider
{
public:

	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest) override;
};