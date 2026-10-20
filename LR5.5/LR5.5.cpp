// LR5.5.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 24

#include <iostream>

using namespace std;

long long f(const int n, const int r, const int k, const int level, int& depth)
{
    if (level > depth)
    {
        depth = level;
        cout << " level = " << level << endl; // вивід нового максимального рівня
    }

    long long res;

    if (n == 0 && r == 0)
        res = 1;
    else if (n > 0 && r >= 0 && r <= n * (k - 1) + 1)
    {
        res = 0;
        for (int i = 0; i <= k - 1; i++)
            res = res + f(n - 1, r - i, k, level + 1, depth);
    }
    else
        res = 0;

    return res;
}

int main()
{
    int n, k, t;
    cout << "n = ";         cin >> n;
    cout << "k = ";         cin >> k;
    cout << "t (0..10) = "; cin >> t;

    long long m = 1; // m = 10^t
    for (int i = 0; i < t; i++)
        m *= 10;

    int depth = 0; // початкове значення глибини рекурсії
    long long x = 0;

    for (int i = 0; i <= n * (k - 1); i++)
        x = (x + f(n, i, k, 1, depth)) % m; // 1 - початкове значення level

    cout << "x = " << x << endl;
    cout << "depth = " << depth << endl;

    return 0;
}

//для перевірки: n = 3; k = 3; t = 2;
// x = 27; Depth = 4; Level = 4