#include <iostream>
using namespace std;

int c(int n, int k)
{
    if (n == k || k == 0)
    {
        return 1;
    }
    else
    {
        return c(n - 1, k - 1) + c(n - 1, k);
    }
}
int main()
{
    int n, k;
    cout << "Nhap n , k: ";
    cin >> n >> k;
    cout << c(n, k);

    return 0;
}