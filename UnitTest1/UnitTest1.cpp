#include "pch.h"
#include "CppUnitTest.h"
#include "../LR5.1/LR5.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestF_Values)
        {
            Assert::AreEqual(1.0, f(0), 1e-9);
            Assert::AreEqual(1.1709098559, f(1), 1e-9);
            Assert::AreEqual(9.8047400080, f(3), 1e-9);
        }

        TEST_METHOD(TestC_X0_Y0)
        {
            double x = 0, y = 0;
            double c = (f(3) + f(x + 1) + 1) / (1 - f(y + 1) * f(y + 1));
            Assert::AreEqual(-32.2767792256, c, 1e-6);
        }
    };
}