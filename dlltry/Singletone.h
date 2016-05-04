#include"ContainersManager.h"

class Singletone
{
private:
	static ContainersManager*c;
public:
	static int SampleRate;
	Singletone()
	{
		c=nullptr;
	}
	static ContainersManager* GetContainer()
	{
		if(c==nullptr)
		{
			c=new ContainersManager;
		}
		return c;
	}
};