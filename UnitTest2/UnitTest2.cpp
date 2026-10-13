#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../LR5.2/LR5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestTerm)
        {
            double a = 1;
            Term(1, 1, a);
            Assert::AreEqual(a, -0.5, 0.0001);
        }

        TEST_METHOD(TestSum)
        {
            double s;
            int n;
            Sum(0.5, 0.0001, n, s);
            Assert::AreEqual(s, log(1.5), 0.001);
        }

        TEST_METHOD(TestSumZero)
        {
            double s;
            int n;
            Sum(0, 0.0001, n, s);
            Assert::AreEqual(s, 0.0, 0.0001);
        }
    };
}