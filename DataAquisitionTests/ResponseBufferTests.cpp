#include "stdafx.h"
#include "../dlltry/ResponseBuffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataAcquisitionTests
{
	TEST_CLASS(ResponseBufferTests)
	{
	public:

		TEST_METHOD(CircularBuffer_ShuldHoldPartOfConvertedValuesInSameOrder_WhenBufferSizeIsNotReached)
		{
			int numberOfValues = 1000;
			int difference = 100;
			int numberOfInsertedValues = numberOfValues - difference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			for (double i = 0; i < numberOfInsertedValues; i++)
			{
				Assert::AreEqual(i, circularBuffer[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldConvertedValuesInSameOrder_WhenBufferSizeIsReached)
		{
			int numberOfValues = 1000;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfValues);

			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i, circularBuffer[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldPartOfConvertedValuesInSameOrder_WhenBufferSizeIsExceeded)
		{
			int numberOfValues = 1000;
			int exceedifference = 100;
			int numberOfInsertedValues = numberOfValues + exceedifference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i + exceedifference, circularBuffer[i]);
			}
		}

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnBufferWithPartOfConvertedValuesInSameOrder_WhenBufferSizeIsExceeded)
		{
			int numberOfValues = 1000;
			int exceedifference = 100;
			int numberOfInsertedValues = numberOfValues + exceedifference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);
			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(numberOfValues);

			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i + exceedifference, (*response)[i]);
			}
		}

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnBufferWithAllOfConvertedValuesInSameOrder_WhenBufferSizeIsReached)
		{
			int numberOfValues = 1000;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfValues);

			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(numberOfValues);

			Assert::AreEqual(numberOfValues, response->size());
			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i, (*response)[i]);
			}
		}

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnNullBuffer_WhenBufferSizeIsNotReached)
		{
			int numberOfValues = 1000;
			int difference = 100;
			int numberOfInsertedValues = numberOfValues - difference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(numberOfValues);

			Assert::IsTrue(nullptr == response);
		}

		//With threshold

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnNull_WhenAllTheValuesAreOverThreshold)
		{
			float threshold = 25;
			int numberOfValues = 1000;
			int exceedifference = 100;
			int numberOfInsertedValues = numberOfValues + exceedifference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);
			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(numberOfValues, threshold);

			Assert::IsTrue(response == nullptr);
		}

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnNull_WhenAllTheValuesAreUnderOrEqualToThreshold)
		{
			float threshold = 1100;
			int numberOfValues = 1000;
			int exceedifference = 100;
			int numberOfInsertedValues = numberOfValues + exceedifference;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);
			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(numberOfValues, threshold);

			Assert::IsTrue(response == nullptr);
		}

		TEST_METHOD(GetBufferWithLoopSize_ShuldReturnBufferWithAllOfConvertedValuesInSameOrder_WhenBufferSizeIsNotReachedAndThresholdIsFound)
		{
			int numberOfValues = 1000;
			float threshold = 25;
			int wantedValues = 900;
			ResponseBuffer circularBuffer = ResponseBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfValues);

			IDataResponse * response = circularBuffer.GetBufferWithLoopSize(wantedValues, threshold);

			Assert::AreEqual(wantedValues, response->size());
			for (double i = 0; i < response->size(); i++)
			{
				Assert::AreEqual(i + threshold, (*response)[i]);
			}
		}

	private:
		void PopulateBuffer(ResponseBuffer &circularBuffer, int numberOfValues)
		{
			for (int i = 0; i < numberOfValues; i++)
			{
				circularBuffer.AddValue(i);
			}
		}
	};
}