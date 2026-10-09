// LR5.3.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 24


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);

int main()
{
    double yp, yk, z;
    int n;

    cout << "yp = "; cin >> yp;
    cout << "yk = "; cin >> yk;
    cout << "n  = "; cin >> n;

    double dy = (yk - yp) / n;

    cout << "-----------------------------" << endl;
    cout << "|     y     |       z       |" << endl;
    cout << "-----------------------------" << endl;

    for (int k = 0; k <= n; k++)
    {
        double y = yp + k * dy;

        if (y < 0)
            continue;

        z = f(1 + sqrt(y) + y) + pow(f(1 + f(1) + pow(f(sqrt(y)), 2)), 2);

        cout << "| " << setw(9) << y << " | " << setw(13) << z << " |" << endl;
    }

    cout << "-----------------------------" << endl;

    return 0;
}

double f(const double x)
{
    if (abs(x) >= 1)
        return sin(x / 2) / (1 + cos(x) * cos(x));
    else
    {
        double S = 0;
        int i = 0;
        double a = 1;
        S = a;
        do
        {
            i++;
            double R = x * x / ((3 * i - 2) * (3 * i - 1) * (3 * i));
            a *= R;
            S += a;
        } while (i < 6);
        return S;
    }
}

//для перевірки: yp = -1; yk = 1; n = 4