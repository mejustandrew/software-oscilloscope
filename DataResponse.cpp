#include"DataResponse.h"

int DataResponse::size()
{
	return loop_size;
}

double DataResponse::operator[] ( int index )
{
	if(over_buffer)
		return samples[(index+add_pos)%number_of_samples];
	return
		samples[index];
}

void DataResponse::Destroy()
{
	over_buffer=false;
	add_pos=0;
}

void DataResponse::Add(double sample)
{
	samples[add_pos]=sample;
	++add_pos;
	if(add_pos==number_of_samples)
	{
		add_pos=0;
		over_buffer=true;
	}
}

bool DataResponse::SetLoopSize(int i)
{
	if(i<add_pos)
	{
		loop_size=add_pos-1;
	return true;	
	}
	return false;
}