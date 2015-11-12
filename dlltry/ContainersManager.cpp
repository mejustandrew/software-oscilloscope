#include"ContainersManager.h"

int ContainersManager::SampleRate=0;

void ContainersManager::Add(double value)
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

DataResponse* ContainersManager::GetSamples(double time_base)
{
	if(isFsimple_used==true)
	{
		if(!fsimple->SetLoopSize(time_base*SampleRate))return nullptr;
		else
		{
		isFsimple_used=false;
		return fsimple;
		}
	}
	else
	{
		if(!gsimple->SetLoopSize(time_base*SampleRate))return nullptr;
		else
		{
		isFsimple_used=true;
		return gsimple;
		}
	}
}

DataResponse* ContainersManager::GetSamples(double time_base,double treshold)
{
	if(isF_used==true)
	{
		if(!f->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
		isF_used=false;
		return f;
		}
	}
	else
	{
		if(!g->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
		isF_used=true;
		return g;
		}
	}
}

double ContainersManager::GetSampleRate()
{
	return SampleRate;
}