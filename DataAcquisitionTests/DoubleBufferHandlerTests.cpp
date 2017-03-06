#include "stdafx.h"
#include "../dlltry/DoubleBufferHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataAcquisitionTests
{
	TEST_CLASS(DoubleBufferHandlerTests)
	{
	public:

		TEST_METHOD(CircularBuffer_ShuldHoldPartOfConvertedValuesInSameOrder_WhenBufferSizeIsNotReached)
		{
			DoubleBufferHandler handler;
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