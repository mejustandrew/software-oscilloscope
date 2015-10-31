#include"ContainersManager.h"
#pragma once
#include"Initialize.h"
class Singletone
{
private:
	static ContainersManager*c;
public:
	Singletone()
	{
		c=nullptr;
	}
	static ContainersManager* GetContainer()
	{
		if(c==nullptr)
		{
			c=new ContainersManager;
			bool result=InternInitialize();
			c->succeded_initialize=result;
		}
		return c;
	}
};