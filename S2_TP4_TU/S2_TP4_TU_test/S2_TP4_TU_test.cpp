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
			Assert::AreEqual(estPair(6), 0);
		}

		TEST_METHOD(TestEstPair2)
		{
			Assert::AreEqual(estPair(7), 1);
		}
	};
}
