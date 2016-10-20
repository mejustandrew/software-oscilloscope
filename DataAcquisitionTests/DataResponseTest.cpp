#include "stdafx.h"
#include "DataResponse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataAcquisitionTests
{		
	TEST_CLASS(DataResponseTest)
	{
	public:

		TEST_METHOD(CircularBuffer_ShuldHoldConvrtedValues_InSameOrder)
		{
			int number_of_values = 10;
			double conversion_coefficient = ( 1 << 16 ) - 1;
			DataResponse *response = new DataResponse(); 
			for(double i = 0;i<number_of_values;++i)
			{
				response->Add(i);
			}

			for(double i = 0; i < number_of_values; ++i)
			{
				Assert::AreEqual(i / conversion_coefficient, (*response)[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldAPartOfConvrtedValues_WhenBufferSizeIsEcceded)
		{
			int number_of_values = 100000;
			double conversion_coefficient = ( 1 << 16 ) - 1;
			DataResponse *response = new DataResponse(); 
			for(double i = 0;i<number_of_values;++i)
			{
				response->Add(i);
			}

			for(double i = 0; i < number_of_values; ++i)
			{
				Assert::AreEqual(i / conversion_coefficient, (*response)[i]);
			}
		}
	};
}