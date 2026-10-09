// lr5.2.cpp
// < прокопчук юлія >
// лабораторна робота № 5.2
// обчислення суми ряду тейлора за допомогою функцій (double)
// варіант 24


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Sum(const double x, const double eps, int& n, double& s);
void Term(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "--------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
        << setw(10) << "ln(x+1)" << "   |"
        << setw(7) << "S" << "      |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "--------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        Sum(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << log(x + 1) << "   |"
            << setw(10) << setprecision(5) << s << "   |"
            << setw(5) << n << "   |"
            << endl;
        x += dx;
    }
    cout << "--------------------------------------------------" << endl;

    return 0;
}

void Sum(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x;
    s = a;
    do {
        n++;
        Term(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

void Term(const double x, const int n, double& a)
{
    double R = -x * n / (n + 1);
    a *= R;
}

//для перевірки: xp = -0.5, xk = 1, dx = 0.25, eps = 0.0001