#include "stdafx.h"
#include "CppUnitTest.h"
#include "StringDTOBuilder.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GUILogicTests
{		
	TEST_CLASS(StringDTOBuilderTests)
	{
		StringDTOBuilder builder;

	public:

		TEST_METHOD(BuildStringModel_ShouldReturnAppropriateValidJson_WhenBothBuffersAreEmpty)
		{
			std::vector<int> leftBuffer;
			std::vector<int> rightBuffer;
			std::string expectedStringModel = "{\"LeftBuffer\":[],\"RightBuffer\":[]}<EOF>";

			std::string actualStringModel = builder.BuildStringModel(leftBuffer, rightBuffer);

			Assert::AreEqual(expectedStringModel, actualStringModel);
		}

		TEST_METHOD(BuildStringModel_ShouldReturnAppropriateValidJson_WhenOnlyRightBufferIsEmpty)
		{
			std::vector<int> leftBuffer;
			std::vector<int> rightBuffer;
			leftBuffer.resize(100);
			std::string expectedStringModel = "{\"LeftBuffer\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
											  "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
											  "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
											  "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],\"RightBuffer\":[]}<EOF>";

			std::string actualStringModel = builder.BuildStringModel(leftBuffer, rightBuffer);

			Assert::AreEqual(expectedStringModel, actualStringModel);
		}

		TEST_METHOD(BuildStringModel_ShouldReturnAppropriateValidJson_WhenOnlyLeftBufferIsEmpty)
		{
			std::vector<int> leftBuffer;
			std::vector<int> rightBuffer;
			rightBuffer.resize(100);
			std::string expectedStringModel = "{\"LeftBuffer\":[],\"RightBuffer\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}<EOF>";

			std::string actualStringModel = builder.BuildStringModel(leftBuffer, rightBuffer);

			Assert::AreEqual(expectedStringModel, actualStringModel);
		}

		TEST_METHOD(BuildStringModel_ShouldReturnAppropriateValidJson_WhenBothBuffersArePopulated)
		{
			std::vector<int> leftBuffer;
			std::vector<int> rightBuffer;
			rightBuffer.resize(100);
			leftBuffer.resize(100);

			std::string expectedStringModel = "{\"LeftBuffer\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],"
				"\"RightBuffer\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
				"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}<EOF>";

			std::string actualStringModel = builder.BuildStringModel(leftBuffer, rightBuffer);

			Assert::AreEqual(expectedStringModel, actualStringModel);
		}
	};
}