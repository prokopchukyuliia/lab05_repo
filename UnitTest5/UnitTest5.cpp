
#include "pch.h"
#include "CppUnitTest.h"
#include "../LR5.5/LR5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLR55
{
    TEST_CLASS(UnitTestLR55)
    {
    public:

        // базовий випадок: f(0, 0) = 1, глибина = 1
        TEST_METHOD(TestBaseCase)
        {
            int depth = 0;
            Assert::AreEqual(1LL, f(0, 0, 3, 1, depth));
            Assert::AreEqual(1, depth);
        }

        // f(0, r) = 0 при r != 0
        TEST_METHOD(TestZeroOutsideBase)
        {
            int depth = 0;
            Assert::AreEqual(0LL, f(0, 1, 3, 1, depth));
        }

        // k = 2: f(n, r) - біноміальні коефіцієнти C(2, r) = 1, 2, 1
        TEST_METHOD(TestBinomialRowK2)
        {
            int depth = 0;
            Assert::AreEqual(1LL, f(2, 0, 2, 1, depth));
            Assert::AreEqual(2LL, f(2, 1, 2, 1, depth));
            Assert::AreEqual(1LL, f(2, 2, 2, 1, depth));
        }

        // сума f(n, i), i = 0..n(k-1), дорівнює k^n (тут 3^4 = 81)
        TEST_METHOD(TestSumEqualsPower)
        {
            const int n = 4, k = 3;
            int depth = 0;
            long long sum = 0;
            for (int i = 0; i <= n * (k - 1); i++)
                sum += f(n, i, k, 1, depth);
            Assert::AreEqual(81LL, sum);
        }

        // глибина рекурсії = n + 1
        TEST_METHOD(TestDepth)
        {
            int depth = 0;
            f(3, 2, 3, 1, depth);
            Assert::AreEqual(4, depth);
        }

        // x = (sum f(n, i)) mod 10^t: n = 5, k = 3, t = 2 => 243 mod 100 = 43
        TEST_METHOD(TestXModM)
        {
            const int n = 5, k = 3;
            const long long m = 100;
            int depth = 0;
            long long x = 0;
            for (int i = 0; i <= n * (k - 1); i++)
                x = (x + f(n, i, k, 1, depth)) % m;
            Assert::AreEqual(43LL, x);
            Assert::AreEqual(6, depth);
        }
    };
}
