#pragma once
#include<string>
#include<vector>
#include<sstream>

class StringDTOBuilder
{
	void ConvertToStringValues(const std::vector<float> &elements, std::string *result)
	{
		int elementsNumber = elements.size() - 1;
		*result += "[";
		if (elementsNumber > 0)
		{
			for (int i = 0; i < elementsNumber; i++)
			{
				*result += std::to_string(elements[i]) + ",";
			}
			*result += std::to_string(elements[elementsNumber]);
		}
		*result += "]";
	}

public:
	_declspec(dllexport) std::string BuildStringModel(const std::vector<float> &leftBuffer, const std::vector<float> &rightBuffer)
	{
		std::string model;
		model.reserve(leftBuffer.size() + rightBuffer.size());
		model += "{\"LeftBuffer\":";
		ConvertToStringValues(leftBuffer, &model); 
		model += ",\"RightBuffer\":";
		ConvertToStringValues(rightBuffer, &model);
		model += "}<EOF>";
		return model;
	}
};