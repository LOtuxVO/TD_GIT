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
			int tab[] = { 1, 2, 3 };
			Assert::AreEqual(sommeTableau(tab, 3), 6);
		}

		TEST_METHOD(Test2)
		{
			int tab2[] = { 5 };
			Assert::AreEqual(sommeTableau(tab2, 1), 5);
		}
		TEST_METHOD(Test3)
		{
			int tab3[] = { -1, 4, -3 };
			Assert::AreEqual(sommeTableau(tab3, 3), 0);
		}
	  /*TEST_METHOD(Test4)
		{
			int tab4[] = {0};
			Assert::AreEqual(sommeTableau(tab4, 1), 0);
		}*/
	};
} 
