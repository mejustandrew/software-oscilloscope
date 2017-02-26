#pragma once
#include<string>
#include<vector>
#include<sstream>

class StringDTOBuilder
{
	template <typename T>
	std::string ConvertToStringValues(const std::vector<T> &elements)
	{
		std::stringstream stream;
		stream << "[";
		int elementsNumber = elements.size() - 1;
		if (elementsNumber > 0)
		{
			for (int i = 0; i < elementsNumber; i++)
			{
				stream << elements[i];
				stream << ",";
			}
			stream << elements[elementsNumber];
			stream << "]";
		}

		return stream.str();
	}

public:
	template<typename T>
	std::string BuildStringModel(const std::vector<T> &leftBuffer, const std::vector<T> &rightBuffer)
	{
		return "{\"LeftBuffer\":" + ConvertToStringValues(leftBuffer) + "," +
			+"\"RightBuffer\":" + ConvertToStringValues(rightBuffer) + "}<EOF>";
	}
};