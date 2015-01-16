#include<atomic> 
#include"DataResponse.h"
class Container
{

	DataResponse *f,*g,*fsimple,*gsimple;
public:
	std::atomic_bool isF_used,isFimple_used;
	double k;
	Container()
	{
		f=new DataResponse();
		fsimple=new DataResponse();
		gsimple=new DataResponse();
		g=new DataResponse();
		isF_used=true;
		isFimple_used=true;
		k= ( 1 << 15 ) / 0.447;
	}
	~Container()
	{
		delete f;
		delete g;
	}
	void Add(double value);
	DataResponse * GetSamples(int number);
	DataResponse * GetSamples(int number,double treshold);
};

