#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\lab 7.3 rec\lab 7.3 rec\lab 7.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 3;
			int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1;
			a[0][1] = 0;
			a[0][2] = 1;

			a[1][0] = 0;
			a[1][1] = 0;
			a[1][2] = 1;

			a[2][0] = 0;
			a[2][1] = 0;
			a[2][2] = 0;

			int s = ZeroElem(a, rowCount, colCount, 0, 0, 0, 0, 0);

			Assert::AreEqual(s, 1);

		}
	};
}
