#include"DataResponse.h"

int DataResponse::size(){	return loop_size; }

double DataResponse::operator[] ( int index ){	return samples[(index+access_pos)%number_of_samples]; }

void DataResponse::Destroy()
{
	over_buffer=false;
	access_pos=0;
	add_pos=0;
}

void DataResponse::Add(double sample)
{
	samples[add_pos]=sample/k;
	++add_pos;
	if(add_pos==number_of_samples)
	{
		add_pos=0;
		over_buffer=true;
	}
}

bool DataResponse::SetLoopSize(int i)
{
	if(over_buffer)
	{
		loop_size=i;
		access_pos=add_pos+1;
		return true;
	}
	if(i<add_pos)
	{
		loop_size=i;
		return true;	
	}
	return false;
}

bool DataResponse::SetSamples(int number,double treshold)
{
	int i=0;
	double converted_treshold=treshold;
	if(over_buffer)
	{
		i=add_pos+1;
		while(number+i<number_of_samples)
		{
			if(converted_treshold>samples[i%number_of_samples] && converted_treshold<=samples[(i+1)%number_of_samples])
			{
				access_pos=i;
				loop_size=number;
				return true;
			}
			++i;
		}
		return false;
	}
	else
	{
		while(number+i<add_pos)
		{
			if(converted_treshold>samples[i] && converted_treshold<=samples[i+1])
			{
				access_pos=i;
				loop_size=number;
				return true;
			}
			++i;
		}
	}
	return false;
}
