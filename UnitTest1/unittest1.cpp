#include "stdafx.h"
#include "CppUnitTest.h"
#include "../point2d.h"
#include "../point2d.cpp"
#include "../string.h"
#include "../string.cpp"

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
		TEST_METHOD(point2dEquality)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsTrue(p1 == p2);
			Assert::IsFalse(p1 == p3);
		}
		TEST_METHOD(point2dInequality)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;
			p3.x = p3.y = 1.f;

			Assert::IsFalse(p1 != p2);
			Assert::IsTrue(p1 != p3);
		}
		TEST_METHOD(point2dSetZero)
		{
			Point2d p1;
			p1.setZero();
			
			Assert::IsTrue(p1.x == 0 && p1.y == 0);
			Assert::IsFalse(p1.x != 0 && p1.y != 0);
		}
		TEST_METHOD(point2dIsBothZero)
		{
			Point2d p1;
			p1.setZero();

			Assert::IsTrue(p1.isBothZero());
			p1.x = 2;
			Assert::IsFalse(p1.isBothZero());
		}
		TEST_METHOD(point2dDistanceTo)
		{
			Point2d p1, p2;
			p1.setZero();
			p2.x = 3;
			p2.y = -4;

			Assert::IsTrue(p1.distanceTo(p2) == 5.f);
		}

		// ----------------------------
		// Tests for String Class
		// ----------------------------

		TEST_METHOD(string)
		{
			Point2d p1, p2, p3;
			p1.x = p2.x = 1.f;
			p1.y = p2.y = 2.f;

			p3 = p1 + p2;

			Assert::IsTrue(p3.x == 2.f && p3.y == 4.f);
		}
	};
}