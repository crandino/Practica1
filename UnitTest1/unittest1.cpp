#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Point2d.h"
#include "../Point2d.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		// ----------------------------
		// Tests for Point2d Class
		// ----------------------------
		
		TEST_METHOD(point2dSum)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p3 = p1 + p2;

			Assert::IsTrue(p3.x == 2.f && p3.y == 4.f);
		}
		TEST_METHOD(point2dDiff)
		{
			Point2d p1, p2, p3;
			p1.x = p1.y = 1.f;
			p2.x = p2.y = 2.f;

			p3 = p1 - p2;
			Assert::IsTrue(p3.x == -1.f && p3.y == -1.f);
			p3 = p2 - p1;
			Assert::IsTrue(p3.x == 1.f && p3.y == 1.f);
		}
		TEST_METHOD(point2dSumAssig)
		{
			Point2d p1, p2;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p1 += p2;
			Assert::IsTrue(p1.x == 2.f && p1.y == 4.f);
			p2 += p1;
			Assert::IsTrue(p2.x == 3.f && p2.y == 6.f);
		}
		TEST_METHOD(point2dDiffAssig)
		{
			Point2d p1, p2;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p1 -= p2;
			Assert::IsTrue(p1.x == 0.f && p1.y == 0.f);
			p2 -= p1;
			Assert::IsTrue(p2.x == 1.f && p2.y == 2.f);
		}

	};
}