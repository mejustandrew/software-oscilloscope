#include<atomic> 
#include"DataResponse.h"
class Container
{

	DataResponse *f,*g;
public:
	std::atomic_bool isF_used;
	Container()
	{
		f=new DataResponse();
		g=new DataResponse();
		isF_used=true;
	}
	~Container()
	{
		delete f;
		delete g;
	}
	void Add(double value);
	DataResponse * GetSamples(int number);
};

