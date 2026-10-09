// LR5.1.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 5.1
// Вкладені цикли
// Варіант 24

// Lab 5_1
#include <iostream>
#include <cmath>

using namespace std;

double f(const double a);  // прототип

int main()
{
    double x, y;

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    double c = (f(3) + f(x + 1) + 1) / (1 - f(y + 1) * f(y + 1));

    cout << "c = " << c << endl;

    return 0;
}

double f(const double a)  // визначення
{
    return (a * a + 1) / (sin(a) * sin(a) + 1);
}