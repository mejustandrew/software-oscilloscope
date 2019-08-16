#include "stdafx.h"
#include "../DataAcquisition/DoubleBufferHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataAcquisitionTests
{
	TEST_CLASS(DoubleBufferHandlerTests)
	{
	public:

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnNull_WhenTheBufferDoesNotHaveEnoughValues)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = 100;
			DoubleBufferHandler handler(numberOfValues);
			PopulateBuffer(handler, numberOfInsertedValues);

			IDataResponse *response = handler.GetBufferWithSizeOf(numberOfValues);

			Assert::IsTrue(response == nullptr);
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnBufferWithInsertedValues_WhenTheBufferHaveEnoughValues)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues;
			DoubleBufferHandler handler(numberOfValues);
			PopulateBuffer(handler, numberOfInsertedValues);

			IDataResponse *response = handler.GetBufferWithSizeOf(numberOfValues);

			Assert::AreEqual(numberOfInsertedValues, response->size());
			for (double i = 0; i < response->size(); i++)
			{
				Assert::AreEqual(i, (*response)[i]);
			}
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnBufferWithInsertedValuesThenNull_WhenTheBufferHaveEnoughValuesThenWhenThereAreNoNewValuesAdded)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues;
			DoubleBufferHandler handler(numberOfValues);
			PopulateBuffer(handler, numberOfInsertedValues);

			IDataResponse *response1 = handler.GetBufferWithSizeOf(numberOfValues);
			IDataResponse *response2 = handler.GetBufferWithSizeOf(numberOfValues);


			Assert::AreEqual(numberOfInsertedValues, response1->size());
			Assert::IsTrue(response2 == nullptr);
			for (double i = 0; i < response1->size(); i++)
			{
				Assert::AreEqual(i, (*response1)[i]);
			}
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnTwoBuffersWithInsertedValues_WhenTheBufferHaveEnoughValuesIntroducedTwice)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues1 = numberOfValues;
			int valuesDifference = 100;
			int numberOfInsertedValues2 = numberOfValues + valuesDifference;
			DoubleBufferHandler handler(numberOfValues);
			PopulateBuffer(handler, numberOfInsertedValues1);

			IDataResponse *response1 = handler.GetBufferWithSizeOf(numberOfValues);
			PopulateBuffer(handler, numberOfInsertedValues2);
			IDataResponse *response2 = handler.GetBufferWithSizeOf(numberOfValues);


			Assert::AreEqual(numberOfInsertedValues1, response1->size());
			Assert::AreEqual(numberOfValues, response2->size());

			for (double i = 0; i < response1->size(); i++)
			{
				Assert::AreEqual(i, (*response1)[i]);
				Assert::AreEqual(i + valuesDifference, (*response2)[i]);
			}
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnNull_WhenTheBufferHasEnoughValuesButTheThresholdIsNotFound)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues;
			int numberOfWantedValues = 200;
			float threshold = 2000;
			DoubleBufferHandler handler(numberOfValues);
			PopulateBuffer(handler, numberOfValues);

			IDataResponse *response = handler.GetBufferWithSizeOf(numberOfWantedValues, threshold);

			Assert::IsTrue(response == nullptr);
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnBufferWithValues_WhenTheBufferHasEnoughValuesAndTheThresholdIsFound)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues = numberOfValues;
			int numberOfWantedValues = 200;
			float threshold = 200;
			DoubleBufferHandler handler(numberOfValues);
			handler.SetSlope(true);
			PopulateBuffer(handler, numberOfValues);

			IDataResponse *response = handler.GetBufferWithSizeOf(numberOfWantedValues, threshold);

			Assert::AreEqual(numberOfWantedValues, response->size());
			for (double i = 0; i < numberOfWantedValues; i++)
			{
				Assert::AreEqual(i + threshold, (*response)[i]);
			}
		}

		TEST_METHOD(GetBufferWithSizeOf_ShuldReturnFourBuffersEqualOnPairsWithInsertedValues_WhenTheBufferHaveEnoughValuesIntroducedFourTimes)
		{
			int numberOfValues = 1000;
			int numberOfInsertedValues1 = numberOfValues;
			int valuesDifference = 100;
			int numberOfInsertedValues2 = numberOfValues + valuesDifference;
			DoubleBufferHandler handler(numberOfValues);

			PopulateBuffer(handler, numberOfInsertedValues1);
			IDataResponse *response1 = handler.GetBufferWithSizeOf(numberOfValues);

			PopulateBuffer(handler, numberOfInsertedValues2);
			IDataResponse *response2 = handler.GetBufferWithSizeOf(numberOfValues);

			PopulateBuffer(handler, numberOfInsertedValues1);
			IDataResponse *response3 = handler.GetBufferWithSizeOf(numberOfValues);

			PopulateBuffer(handler, numberOfInsertedValues2);
			IDataResponse *response4 = handler.GetBufferWithSizeOf(numberOfValues);

			Assert::IsTrue(response1 == response3);
			Assert::IsTrue(response2 == response4);
			Assert::IsFalse(response1 == response2);
			Assert::IsFalse(response2 == response3);
			Assert::AreEqual(numberOfInsertedValues1, response1->size());
			Assert::AreEqual(numberOfValues, response2->size());
			Assert::AreEqual(numberOfInsertedValues1, response3->size());
			Assert::AreEqual(numberOfValues, response4->size());
			for (double i = 0; i < response1->size(); i++)
			{
				Assert::AreEqual(i, (*response1)[i]);
				Assert::AreEqual(i, (*response3)[i]);
				Assert::AreEqual(i + valuesDifference, (*response2)[i]);
				Assert::AreEqual(i + valuesDifference, (*response4)[i]);
			}
		}

	private:
		void PopulateBuffer(DoubleBufferHandler &circularBuffer, int numberOfValues)
		{
			for (int i = 0; i < numberOfValues; i++)
			{
				circularBuffer.AddValue(i);
			}
		}
	};
}