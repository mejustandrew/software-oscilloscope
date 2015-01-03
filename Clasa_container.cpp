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
}

DataResponse* Container::GetSamples(int number)
{
	int i=0;
	if(isF_used==true)
	{
		if(!f->SetLoopSize(number))return nullptr;
		else
		{
		isF_used=false;
		return f;
		}
	}
	else
	{
		if(!g->SetLoopSize(number))return nullptr;
		else
		{
		isF_used=true;
		return g;
		}
	}
}
