#pragma once
#include"IDataProvider.h"

class AudioDataProvider : public IDataProvider
{
public:

	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest) override;
};