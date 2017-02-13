#include "stdafx.h"
#include "DataResponse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool DoubleEquals(double a, double b, double epsilon)
{
	return abs(a - b) < epsilon;
}

namespace DataAcquisitionTests
{
	TEST_CLASS(DataResponseTest)
	{
	public:

		TEST_METHOD(CircularBuffer_ShuldHoldConvertedValues_InSameOrder)
		{
			int number_of_values = 10;
			double conversion_coefficient = (1 << 16) - 1;
			DataResponse *response = new DataResponse();
			for (double i = 0; i < number_of_values; ++i)
			{
				response->Add(i);
			}
			response->SetLoopSize(number_of_values);
			for (double i = 0; i < number_of_values; ++i)
			{
				Assert::AreEqual(i / conversion_coefficient, (*response)[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldAPartOfConvertedValues_WhenBufferSizeIsReached)
		{
			int number_of_values = 64000;
			int buffer_size = 64000;
			double conversion_coefficient = (1 << 16) - 1;
			DataResponse *response = new DataResponse();
			for (double i = 0; i < number_of_values; ++i)
			{
				response->Add(i);
			}
			response->SetLoopSize(buffer_size);
			for (double i = 0.0; i < buffer_size; ++i)
			{
				Assert::AreEqual(i / conversion_coefficient, (*response)[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldAPartOfConvertedValues_WhenBufferSizeIsExceeded)
		{
			int number_of_values = 7;
			int buffer_size = 5;
			double *inserted_values = new double[number_of_values];
			double *actual_values = new double[number_of_values];


			double conversion_coefficient = (1 << 16) - 1;
			DataResponse *response = new DataResponse(buffer_size);
			for (int i = 0; i < number_of_values; i++)
			{
				inserted_values[i] = i;
				response->Add(i);
			}
			bool are_equal = true;
			int overbuffer = number_of_values % buffer_size;
			response->SetLoopSize(buffer_size);
			for (int i = 0; i < buffer_size; ++i)
			{
				actual_values[i] = (*response)[i] * conversion_coefficient;
				if (!DoubleEquals(inserted_values[overbuffer], (*response)[i]*conversion_coefficient, 0.001))
					are_equal = false;
				overbuffer++;
			}

			delete[]inserted_values;
			Assert::IsTrue(are_equal);
		}
	};
}