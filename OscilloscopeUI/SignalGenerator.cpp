#include "SignalGenerator.h"

void SignalGenerator::SetSignalSlope(bool positive)
{
	response->SetSlope(positive);
}
