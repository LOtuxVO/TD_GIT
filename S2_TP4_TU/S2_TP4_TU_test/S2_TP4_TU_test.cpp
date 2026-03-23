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

		TEST_METHOD(Test)
		{
			Assert::AreEqual(factorielle(0), 1);
		}

		TEST_METHOD(Test2)
		{
			Assert::AreEqual(factorielle(1), 1);
		}
		TEST_METHOD(Test3)
		{
			Assert::AreEqual(factorielle(4), 24);
		}
		TEST_METHOD(Test4)
		{
			Assert::AreEqual(factorielle(5), 120);
		}
	};
} 
