#pragma once
#include"IDataResponse.h"

class DataResponse: public IDataResponse
{
	double*samples,conversion_coefficient;
	int number_of_samples,//used to initialize samples vector
		add_pos,//to add on it, and it's the last position for added sample
		access_pos,//used when samples are read with operator
		loop_size;//used to specify the size of iterations
	bool over_buffer;
public:
	DataResponse()
	{
		over_buffer=false;
		loop_size=0;
		access_pos=0;
		add_pos=0;
		number_of_samples=64000;
		samples=new double[number_of_samples];
		conversion_coefficient= ( 1 << 16 )-1;
		for(int i=0;i<number_of_samples;++i)
		{
			samples[i]=0;
		}
	}
	_declspec(dllexport) int size();
	_declspec(dllexport) double operator[] ( int index );
	_declspec(dllexport) void Destroy();
	_declspec(dllexport) void Add(double sample);
	_declspec(dllexport) bool SetSamples(int number,double treshold);
	_declspec(dllexport) bool SetLoopSize(int i);
};