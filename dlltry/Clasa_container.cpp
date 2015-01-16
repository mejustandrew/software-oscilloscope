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

DataResponse* Container::GetSamples(int number)
{
	if(isFsimple_used==true)
	{
		if(!fsimple->SetLoopSize(number))return nullptr;
		else
		{
		isFsimple_used=false;
		return fsimple;
		}
	}
	else
	{
		if(!gsimple->SetLoopSize(number))return nullptr;
		else
		{
		isFsimple_used=true;
		return gsimple;
		}
	}
}

DataResponse* Container::GetSamples(int number,double treshold)
{
	if(isF_used==true)
	{
		if(!f->SetSamples(number,treshold))return nullptr;
		else
		{
		isF_used=false;
		return f;
		}
	}
	else
	{
		if(!g->SetSamples(number,treshold))return nullptr;
		else
		{
		isF_used=true;
		return g;
		}
	}
}