#include"Initialize.h"
#include<Windows.h>
#include<conio.h>
#include"DataRequest.h"
int main()
{
	Initialize();

	//Container *cont=Singletone::GetContainer();
	DataRequest d1(0.025,1);
	IDataResponse *f=GetSignalSamples(&d1);
	for(int i=0;i<f->size();++i)
	{
		std::cout<<i<<".  "<<(*f)[i]<<"\n";
	}
	std::cout<<"\n";
	f=GetSignalSamples(&d1);
	int c=f->size();
	for(int i=0;i<f->size();++i)
	{
		std::cout<<i<<".  "<<(*f)[i]<<"\n";
	}

	_getch();
	return 0;
}