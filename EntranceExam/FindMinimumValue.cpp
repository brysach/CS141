#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double, double);
double middle(double, double, int);

int main()
{
    double a;
    const double tol = 1e-7;
    double delta = 0.1;
    double first = 1.0;
    double second = 2.0;
    int n = 1;
    double x = middle(first, second, n);
    n++;
    cin >> a;
    double y = f(x, a);
    double minimumOfFunction = y;
    double distance = second - first;
    // bool noMore = false;
    //  cout << showpoint << setprecision(8) << x << endl;

    while (distance > tol)
    {
        if (f(x + tol, a) < y)
        {
            first = x + tol;
        }
        else if (f(x - tol, a) < y)
        {
            second = x - tol;
        }
        else
        {
            // noMore = true;
            break;
        }
        n++;
        x = middle(first, second, n);
        y = f(x, a);
        if (y < minimumOfFunction)
        {
            minimumOfFunction = y;
        }
        distance = second - first;
    }
    // cout << ((x * x) / log(x)) + a * x;
    cout << showpoint << setprecision(8) << minimumOfFunction;
    return 0;
}

double f(double x, double a)
{
    return ((x * x) / log(x)) + a * x;
}

double middle(double first, double second, int n)
{
    return (first + second) / 2.0;
}