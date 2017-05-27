#include "IDualChannelDataProvider.h"

IDualChannelDataProvider::IDualChannelDataProvider()
{
	container = new DataContainer;
}

IDualChannelDataProvider::~IDualChannelDataProvider()
{
	delete container;
}
