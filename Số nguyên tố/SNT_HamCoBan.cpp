#include <iostream>
#include <math.h>
using namespace std;

bool check(int n)
{
    if (n == 2)
    {
        return true;
    }
    else if (n < 2 || n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i < sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if (!check(n))
    {
        cout
            << n << " K la so nguyen to";
    }
    else
    {
        cout << n << " la so nguyen to";
    }
}