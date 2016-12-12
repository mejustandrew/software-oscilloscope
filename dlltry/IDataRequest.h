#pragma once
class IDataRequest
{
public:
	virtual double GetTimeBase() = 0;
	virtual double GetTreshold() = 0;
};