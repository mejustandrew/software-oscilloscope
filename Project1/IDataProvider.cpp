#include "IDataProvider.h"

IDataProvider::IDataProvider()
{
	container = new DataContainer;
}

IDataProvider::~IDataProvider()
{
	delete container;
}
