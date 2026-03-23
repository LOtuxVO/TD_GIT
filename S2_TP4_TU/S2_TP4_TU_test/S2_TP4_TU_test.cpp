#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../S2_TP4_TU/TP4_TU.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace S2TP4TUtest
{
	TEST_CLASS(S2TP4TUtest)
	{
	public:

		TEST_METHOD(Testmax)
		{
			Assert::AreEqual(max2(5, 3), 5);
		}

		TEST_METHOD(Testmax2)
		{
			Assert::AreEqual(max2(3, 5), 5);
		}
		TEST_METHOD(Testmax3)
		{
			Assert::AreEqual(max2(-1, -8), -1);
		}
		TEST_METHOD(Testmax4)
		{
			Assert::AreEqual(max2(4, 4), 4);
		}
	};
}
