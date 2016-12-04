#include<atomic> 
#include"DataResponse.h"
#pragma once
class ContainersManager
{

	DataResponse *fRight,*gRight,*fsimpleRight,*gsimpleRight;
	DataResponse *fLeft,*gLeft,*fsimpleLeft,*gsimpleLeft;
public:
	std::atomic_bool isFRight_used,isFsimpleRight_used;
	std::atomic_bool isFLeft_used,isFsimpleLeft_used;

	double k;
	static int SampleRate;
	ContainersManager()
	{
		fRight=new DataResponse();
		fsimpleRight=new DataResponse();
		gsimpleRight=new DataResponse();
		gRight=new DataResponse();
		isFRight_used=true;
		isFsimpleRight_used=true;

		fLeft=new DataResponse();
		fsimpleLeft=new DataResponse();
		gsimpleLeft=new DataResponse();
		gLeft=new DataResponse();
		isFLeft_used=true;
		isFsimpleLeft_used=true;

		k= ( 1 << 15 ) / 0.447;
	}
	~ContainersManager()
	{
		delete fRight;
		delete gRight;
		delete fsimpleRight;
		delete gsimpleRight;

		delete fLeft;
		delete gLeft;
		delete fsimpleLeft;
		delete gsimpleLeft;
	}
	void AddToLeftBuffer(double value);
	void AddToRightBuffer(double value);
	void AddSamplePair(double leftValue, double rightValue);
	double GetSampleRate();
	DataResponse * GetRightSamples(int numberOfSamples);
	DataResponse * GetLeftSamples(int numberOfSamples);
	DataResponse * GetRightSamples(double time_base,double treshold);
	DataResponse * GetLeftSamples(double time_base,double treshold);
};

