#include "stdafx.h"
#include "../dlltry/CircularBuffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataAcquisitionTests
{
	TEST_CLASS(CircularBufferTests)
	{
	public:

		TEST_METHOD(CircularBuffer_ShuldHoldPartOfConvertedValuesInSameOrder_WhenBufferSizeIsNotReached)
		{
			int numberOfValues = 1000;
			int difference = 100;
			int numberOfInsertedValues = numberOfValues - difference;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			for (double i = 0; i < numberOfInsertedValues; i++)
			{
				Assert::AreEqual(i, circularBuffer[i]);
			}
		}

		TEST_METHOD(CircularBuffer_ShuldHoldConvertedValuesInSameOrder_WhenBufferSizeIsReached)
		{
			int numberOfValues = 1000;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);

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
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);

			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i + exceedifference, circularBuffer[i]);
			}
		}

		TEST_METHOD(GetNumberOfAvaiableValues_ShuldReturnNumberOfIntroducedValues_WhenBufferSizeIsReached)
		{
			int numberOfValues = 1000;
			int expectedNumberOfValues = numberOfValues;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfValues);

			int actualNumberOfValues = circularBuffer.GetNumberOfAvaiableValues();

			Assert::AreEqual(numberOfValues, actualNumberOfValues);
		}

		TEST_METHOD(GetNumberOfAvaiableValues_ShuldReturnNumberOfIntroducedValues_WhenBufferSizeIsNotReached)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues - 100;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			int actualNumberOfValues = circularBuffer.GetNumberOfAvaiableValues();

			Assert::AreEqual(numberOfInsertedValues, actualNumberOfValues);
		}

		TEST_METHOD(GetNumberOfAvaiableValues_ShuldReturnBufferSize_WhenBufferSizeIsExceeded)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues + 100;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			int actualNumberOfValues = circularBuffer.GetNumberOfAvaiableValues();

			Assert::AreEqual(numberOfValues, actualNumberOfValues);
		}

		TEST_METHOD(ResetBuffer_ShuldDefaultBackTheBuffer_WhenBufferHasBeenModified)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues + 100;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfInsertedValues);
			int expectedNumberOfValues = 0;

			circularBuffer.ResetBuffer();
			int actualNumberOfValues = circularBuffer.GetNumberOfAvaiableValues();

			Assert::AreEqual(expectedNumberOfValues, actualNumberOfValues);
		}

		TEST_METHOD(CircularBuffer_ShuldHoldPartOfConvertedValuesInSameOrder_WhenBufferSizeIsExceededAfterBufferHasBeenReseted)
		{
			int numberOfValues = 1000;
			int exceedifference = 100;
			int numberOfInsertedValues = numberOfValues + exceedifference;
			CircularBuffer circularBuffer = CircularBuffer(numberOfValues);
			PopulateBuffer(circularBuffer, numberOfInsertedValues);

			circularBuffer.ResetBuffer();

			PopulateBuffer(circularBuffer, numberOfInsertedValues);
			for (double i = 0; i < numberOfValues; i++)
			{
				Assert::AreEqual(i + exceedifference, circularBuffer[i]);
			}
		}

	private:
		void PopulateBuffer(CircularBuffer &circularBuffer, int numberOfValues)
		{
			for (int i = 0; i < numberOfValues; i++)
			{
				circularBuffer.AddValue(i);
			}
		}
	};
}