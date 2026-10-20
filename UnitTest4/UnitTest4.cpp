
#include "pch.h"
#include "CppUnitTest.h"
#include "../LR5.4/LR5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLR54
{
    TEST_CLASS(UnitTestLR54)
    {
    public:

        // g(1) = S5(1, 1)
        TEST_METHOD(TestG)
        {
            Assert::AreEqual(0.950246501797441, g(1), 1e-12);
        }

        // сума з одного доданка (N = 1): усі способи дають g(1)
        TEST_METHOD(TestOneTerm)
        {
            const double expected = 0.950246501797441;
            Assert::AreEqual(expected, S1(1, 1, 1, 0), 1e-12);
            Assert::AreEqual(expected, S2(1, 1, 1, 0), 1e-12);
            Assert::AreEqual(expected, S3(1, 1, 1), 1e-12);
            Assert::AreEqual(expected, S4(1, 1, 1), 1e-12);
            Assert::AreEqual(expected, S5(1, 1), 1e-12);
        }

        // N = 10: еталонне значення суми
        TEST_METHOD(TestSumN10)
        {
            const double expected = 9.25741775160689;
            Assert::AreEqual(expected, S1(1, 10, 10, 0), 1e-9);
            Assert::AreEqual(expected, S2(1, 10, 1, 0), 1e-9);
            Assert::AreEqual(expected, S3(1, 10, 10), 1e-9);
            Assert::AreEqual(expected, S4(1, 10, 1), 1e-9);
            Assert::AreEqual(expected, S5(1, 10), 1e-9);
        }

        // N = 100: усі рекурсивні способи збігаються з ітераційним
        TEST_METHOD(TestRecursiveEqualsIterative)
        {
            const int K = 1, N = 100;
            const double control = S5(K, N);
            Assert::AreEqual(control, S1(K, N, N, 0), 1e-9);
            Assert::AreEqual(control, S2(K, N, K, 0), 1e-9);
            Assert::AreEqual(control, S3(K, N, N), 1e-9);
            Assert::AreEqual(control, S4(K, N, K), 1e-9);
        }
    };
}
