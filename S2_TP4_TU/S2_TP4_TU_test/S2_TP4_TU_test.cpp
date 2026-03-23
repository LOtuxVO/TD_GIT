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
			Assert::AreEqual(contientMajuscule("bonjour"), 0);
		}

		TEST_METHOD(Test2)
		{
			Assert::AreEqual(contientMajuscule("BonJour"), 1);
		}
		TEST_METHOD(Test3)
		{
			Assert::AreEqual(contientMajuscule("ABC"), 1);
		}
		TEST_METHOD(Test4)
		{
			Assert::AreEqual(contientMajuscule(""), 0);
		}
		TEST_METHOD(TestNULL)
		{
			Assert::AreEqual(contientMajuscule("null"), 0);
		}
	};
} 
