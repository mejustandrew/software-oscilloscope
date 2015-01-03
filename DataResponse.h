#pragma once
#include"IDataResponse.h"

class DataResponse: public IDataResponse
{
	double*samples;
	int number_of_samples,//used to initialize samples vector
		add_pos,//to add on it, and it's the last position for added sample
		loop_size;//used to specify the size of iterations
	bool over_buffer;
public:
	DataResponse()
	{
		over_buffer=false;
		loop_size=0;
		add_pos=0;
		number_of_samples=100000;
		samples=new double[number_of_samples];
		for(int i=0;i<number_of_samples;++i)
		{
			samples[i]=0;
		}
	}
	int size();
	double operator[] ( int index );
	void Destroy();
	void Add(double sample);
	bool SetLoopSize(int i);
};