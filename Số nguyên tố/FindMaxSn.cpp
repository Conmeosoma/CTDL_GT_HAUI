#include <iostream>
#include <math.h>
using namespace std;
int a[99];
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

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void nhap()
{
    for (int i = 0; i < 4; i++)
    {
        do
        {
            cout << "Nhap so nguyen to thu " << (i + 1) << ": ";
            cin >> a[i];
        } while (!check(a[i]));
    }
}
void xuLy()
{
    int max = a[0];
    for (int i = 1; i < 4; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << "So nguyen to lon nhat la: " << max;
}
int main()
{
    nhap();
    xuLy();
    return 0;
}