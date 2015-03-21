#include"Clasa_container.h"
#pragma once
#include"Initialize.h"
class Singletone
{
private:
	static Container*c;
public:
	Singletone()
	{
		c=nullptr;
	}
	static Container* GetContainer()
	{
		if(c==nullptr)
		{
			c=new Container;
			Initialize(c);
		}
		return c;
	}
};