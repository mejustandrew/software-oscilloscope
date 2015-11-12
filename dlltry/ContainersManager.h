#include<atomic> 
#include"DataResponse.h"
#pragma once
class ContainersManager
{

	DataResponse *f,*g,*fsimple,*gsimple;
public:
	std::atomic_bool isF_used,isFsimple_used;
	double k;
	static int SampleRate;
	ContainersManager()
	{
		f=new DataResponse();
		fsimple=new DataResponse();
		gsimple=new DataResponse();
		g=new DataResponse();
		isF_used=true;
		isFsimple_used=true;
		k= ( 1 << 15 ) / 0.447;
	}
	~ContainersManager()
	{
		delete f;
		delete g;
		delete fsimple;
		delete gsimple;
	}
	void Add(double value);
	double GetSampleRate();
	DataResponse * GetSamples(double time_base);
	DataResponse * GetSamples(double time_base,double treshold);
};

