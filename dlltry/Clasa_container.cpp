#include"Clasa_container.h"

void Container::Add(double value)
{
	if(isF_used)
	{
		f->Add(value);
	}
	else
	{
		g->Add(value);
	}

	if(isFsimple_used)
	{
		fsimple->Add(value);
	}
	else
	{
		gsimple->Add(value);
	}
}

DataResponse* Container::GetSamples(double time_base)
{
	if(isFsimple_used==true)
	{
		if(!fsimple->SetLoopSize(time_base*sample_rate))return nullptr;
		else
		{
		isFsimple_used=false;
		return fsimple;
		}
	}
	else
	{
		if(!gsimple->SetLoopSize(time_base*sample_rate))return nullptr;
		else
		{
		isFsimple_used=true;
		return gsimple;
		}
	}
}

DataResponse* Container::GetSamples(double time_base,double treshold)
{
	if(isF_used==true)
	{
		if(!f->SetSamples(time_base*sample_rate,treshold))return nullptr;
		else
		{
		isF_used=false;
		return f;
		}
	}
	else
	{
		if(!g->SetSamples(time_base*sample_rate,treshold))return nullptr;
		else
		{
		isF_used=true;
		return g;
		}
	}
}

double Container::GetSampleRate()
{
	return sample_rate;
}