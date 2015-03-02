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
		
		TEST_METHOD(stringConstrEmpty)
		{
			String s1;

			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(stringConstrChar)
		{
			String s1("Hello");
			char *p2 = "Dog";
			String s2 = p2;
			char *p3 = NULL;
			String s3 = p3;
			String s4("%s %d %s", "I am", 27, "years old");

			Assert::IsTrue(s1 == "Hello");
			Assert::IsTrue(s2 == "Dog");
			Assert::IsTrue(s3 == "");
			Assert::IsTrue(s4 == "I am 27 years old");
		}
		TEST_METHOD(stringConstrString)
		{
			String s1;
			String s2(s1);
			String s3("Hello");
			String s4(s3);

			Assert::IsTrue(s1 == "");
			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s3 == "Hello");
			Assert::IsTrue(s3 == s4);
		}
		TEST_METHOD(stringEqualityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello";

			Assert::IsTrue(s1 == "Hello");
			Assert::IsFalse(s1 == p1);
			Assert::IsTrue(s1 == p2);
		}
		TEST_METHOD(stringInequalityChar)
		{
			String s1("Hello");
			char *p1 = NULL;
			char *p2 = "Hello, darling";

			Assert::IsTrue(s1 != "Hello, darling");
			Assert::IsTrue(s1 != p1);
			Assert::IsTrue(s1 != p2);
		}
		TEST_METHOD(stringEqualityString)
		{
			String s1("Hello");
			String s2("Hello");

			Assert::IsTrue(s1 == s2);
		}
		TEST_METHOD(stringInequalityString)
		{
			String s1("Hello");
			String s2("Hello, darling...");

			Assert::IsTrue(s1 != s2);
		}
		TEST_METHOD(stringAssignChar)
		{
			String s1("Hello");
			String s2 = "Hello, darling...";
			char *p = NULL;
			String s3 = p;
			String s4 = "Hello";

			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s2);
			Assert::IsTrue(s1 != s3);
			Assert::IsTrue(s1 == s4);
		}
		TEST_METHOD(stringAssignString)
		{
			String s1("Hello");
			String s2 = s1;
			String s3("Hello, darling...");
			String s4 = s3;

			Assert::IsTrue(s1 == s2);
			Assert::IsTrue(s1 != s4);
		}
		TEST_METHOD(stringConcatChar)
		{
			String s1("Hello");
			s1 += "world";
			Assert::IsTrue(s1 == "Helloworld");
			char *p = NULL;
			s1 += p;
			Assert::IsTrue(s1 == "");
		}
		TEST_METHOD(stringConcatString)
		{
			String s1("Hello");
			String s2("world");
			s1 += s2;
			Assert::IsTrue(s1 == "Helloworld");
		}
		TEST_METHOD(stringGetLength)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.getLength() == 5);
			Assert::IsTrue(s2.getLength() == 0);
		}
		TEST_METHOD(stringCapacity)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(s1.capacity() == 6);
			Assert::IsTrue(s2.capacity() == 1);
		}
		TEST_METHOD(stringGetString)
		{
			String s1("Hello");
			String s2;

			Assert::IsTrue(strcmp(s1.getString(),"Hello") == 0);
			Assert::IsTrue(strcmp(s2.getString(),"") == 0);
		}
		TEST_METHOD(stringClear)
		{
			String s1("Hello");
			s1.clear();

			Assert::IsTrue(strcmp(s1.getString(), "") == 0);
		}
		
	};
}