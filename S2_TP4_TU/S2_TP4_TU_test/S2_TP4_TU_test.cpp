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

		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(4), 1);
		}

		TEST_METHOD(TestEstPair2)
		{
			Assert::AreEqual(estPair(7), 0);
		}
		TEST_METHOD(TestEstPair3)
		{
			Assert::AreEqual(estPair(0), 1);
		}
		TEST_METHOD(TestEstPair4)
		{
			Assert::AreEqual(estPair(-2), 1);
		}
		TEST_METHOD(TestEstPair5)
		{
			Assert::AreEqual(estPair(-3), 0);
		}
	};
}
