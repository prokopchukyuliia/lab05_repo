#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../LR5.3/LR5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(TestFZero)
        {
            // гілка ряду: x = 0, усі доданки після першого нульові
            Assert::AreEqual(f(0), 1.0, 0.0001);
        }

        TEST_METHOD(TestFSmall)
        {
            // гілка ряду: |x| < 1, S ≈ 1.041754
            Assert::AreEqual(f(0.5), 1.04175, 0.0001);
        }

        TEST_METHOD(TestFLarge)
        {
            // гілка формули: |x| >= 1
            Assert::AreEqual(f(2), sin(1.0) / (1 + cos(2.0) * cos(2.0)), 0.0001);
        }
    };
}