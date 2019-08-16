#pragma once
#include"IDualChannelDataProvider.h"

class AudioDualChannelDataProvider : public IDualChannelDataProvider
{
public:
	virtual void SetLeftSlope(bool positive);
	virtual void SetRightSlope(bool positive);
	virtual DataContainer* GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest) override;
};