#pragma once


class ISamplesHolder
{
public:
	virtual void AddLeftSample(float sample) = 0;
	virtual void AddRightSampele(float sample) = 0;
};