#include "SignalTypesAvaiableProperties.h"

SinusoidalTypeAvaiableProperties::SinusoidalTypeAvaiableProperties()
{
	amplitudeLevels = { "500", "250", "100" , "50" , "10" };
	frequencyLevels = { "20000", "10000", "5000", "1000", "500" , "100" , "50", "10", "1"};
}

GaussianNoiseTypeAvaiableProperties::GaussianNoiseTypeAvaiableProperties()
{
	varianceLevels = { "5", "1", "0.5", "0.2" };
	meanLevels = { "-2", "-1", "0", "1", "2" };
}

PWMTypeAvaiableProperties::PWMTypeAvaiableProperties()
{
	amplitudeLevels = { "250", "100" , "50" , "10" };
	dutyCycleLevels = { "100", "75", "50", "25", "0" };
}