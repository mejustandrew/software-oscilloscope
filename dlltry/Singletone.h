#include"Clasa_container.h"

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
		}
		return c;
	}
};