#include <iostream>
#include <math.h>
using namespace std;
bool check(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i <= sqrt(n); i++)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
        return true;
    }
}
int main()
{
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if (!check(n))
    {
        cout << n << " K la so nguyen to";
    }
    else
    {
        cout << n << " la so nguyen to";
    }
}