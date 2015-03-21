#include<atomic> 
#include"DataResponse.h"
class Container
{

	DataResponse *f,*g,*fsimple,*gsimple;
public:
	std::atomic_bool isF_used,isFsimple_used;
	double k,sample_rate;
	Container()
	{
		f=new DataResponse();
		fsimple=new DataResponse();
		gsimple=new DataResponse();
		g=new DataResponse();
		isF_used=true;
		isFsimple_used=true;
		k= ( 1 << 15 ) / 0.447;
		sample_rate=0;
	}
	~Container()
	{
		delete f;
		delete g;
	}
	void Add(double value);
	void SetSampleRate(double value){ sample_rate=value; }
	DataResponse * GetSamples(double time_base);
	DataResponse * GetSamples(double time_base,double treshold);
};

