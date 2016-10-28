#include"ContainersManager.h"

int ContainersManager::SampleRate=0;

void ContainersManager::AddSamplePair(double leftValue, double rightValue)
{
	if(isFLeft_used)
	{
		fLeft->Add(leftValue);
	}
	else
	{
		gLeft->Add(leftValue);
	}

	if(isFsimpleLeft_used)
	{
		fsimpleLeft->Add(leftValue);
	}
	else
	{
		gsimpleLeft->Add(leftValue);
	}

	if(isFRight_used)
	{
		fRight->Add(rightValue);
	}
	else
	{
		gRight->Add(rightValue);
	}

	if(isFsimpleRight_used)
	{
		fsimpleRight->Add(rightValue);
	}
	else
	{
		gsimpleRight->Add(rightValue);
	}
}

void ContainersManager::AddToLeftBuffer(double value)
{
	if(isFLeft_used)
	{
		fLeft->Add(value);
	}
	else
	{
		gLeft->Add(value);
	}

	if(isFsimpleLeft_used)
	{
		fsimpleLeft->Add(value);
	}
	else
	{
		gsimpleLeft->Add(value);
	}
}

void ContainersManager::AddToRightBuffer(double value)
{
	if(isFRight_used)
	{
		fRight->Add(value);
	}
	else
	{
		gRight->Add(value);
	}

	if(isFsimpleRight_used)
	{
		fsimpleRight->Add(value);
	}
	else
	{
		gsimpleRight->Add(value);
	}
}

DataResponse* ContainersManager::GetRightSamples(int numberOfSamples)
{
	if(isFsimpleRight_used==true)
	{
		if(!fsimpleRight->SetLoopSize(numberOfSamples))return nullptr;
		else
		{
			isFsimpleRight_used=false;
			return fsimpleRight;
		}
	}
	else
	{
		if(!gsimpleRight->SetLoopSize(numberOfSamples))return nullptr;
		else
		{
			isFsimpleRight_used=true;
			return gsimpleRight;
		}
	}
}

DataResponse* ContainersManager::GetRightSamples(double time_base,double treshold)
{
	if(isFRight_used==true)
	{
		if(!fRight->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
			isFRight_used=false;
			return fRight;
		}
	}
	else
	{
		if(!gRight->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
			isFRight_used=true;
			return gRight;
		}
	}
}

DataResponse* ContainersManager::GetLeftSamples(int numberOfSamples)
{
	if(isFsimpleLeft_used==true)
	{
		if(!fsimpleLeft->SetLoopSize(numberOfSamples))return nullptr;
		else
		{
			isFsimpleLeft_used=false;
			return fsimpleLeft;
		}
	}
	else
	{
		if(!gsimpleLeft->SetLoopSize(numberOfSamples))return nullptr;
		else
		{
			isFsimpleLeft_used=true;
			return gsimpleLeft;
		}
	}
}

DataResponse* ContainersManager::GetLeftSamples(double time_base,double treshold)
{
	if(isFLeft_used==true)
	{
		if(!fLeft->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
			isFLeft_used=false;
			return fLeft;
		}
	}
	else
	{
		if(!gLeft->SetSamples(time_base*SampleRate,treshold))return nullptr;
		else
		{
			isFLeft_used=true;
			return gLeft;
		}
	}
}

double ContainersManager::GetSampleRate()
{
	return SampleRate;
}