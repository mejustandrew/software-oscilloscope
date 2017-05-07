#pragma once 

class _declspec(dllexport) IDataResponse
{
public:
	virtual int size()=0;

	virtual double operator[] ( int index )=0;

	virtual void Destroy() = 0;
};
