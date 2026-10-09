// LR5.5.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 24

#include <iostream>

using namespace std;

long long f(const int n, const int r, const int k, const long long m)
{
    if (n == 0 && r == 0)
        return 1 % m;

    if (n > 0 && r >= 0 && r <= n * (k - 1) + 1)
    {
        long long s = 0;
        for (int i = 0; i <= k - 1; i++)
            s = (s + f(n - 1, r - i, k, m)) % m;
        return s;
    }

    return 0;
}

int main()
{
    int n, k, t;

    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;
    cout << "t = "; cin >> t;

    long long m = 1;
    for (int i = 1; i <= t; i++)
        m *= 10;

    long long x = 0;
    for (int i = 0; i <= n * (k - 1); i++)
        x = (x + f(n, i, k, m)) % m;

    cout << "x = " << x << endl;

    return 0;
}

//для перевірки: n = 1; k = 2; t = 0; x = 0