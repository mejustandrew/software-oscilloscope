#pragma once
#include <string>
#include <vector>

using namespace std;

struct SinusoidalTypeAvaiableProperties
{
	SinusoidalTypeAvaiableProperties();
	vector<string> amplitudeLevels;
	vector<string> frequencyLevels;
};

struct GaussianNoiseTypeAvaiableProperties
{
	GaussianNoiseTypeAvaiableProperties();
	vector<string> varianceLevels;
	vector<string> meanLevels;
};

struct PWMTypeAvaiableProperties
{
	PWMTypeAvaiableProperties();
	vector<string> amplitudeLevels;
	vector<string> dutyCycleLevels;
};