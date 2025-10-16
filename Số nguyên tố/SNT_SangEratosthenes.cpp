#include <iostream>
#include <math.h>
using namespace std;
// Neu ban muon sang cac SNT k vuot qua n
// phai tao 1 mang kich t (n + 1) phan tu

int prime[10000001];
void Sang()
{
    for (int i = 0; i <= 10000001, i++)
    {
        prime[i] = 1;
        prime[0] = prime[1] = 0;
        for (int i = 0; i <= 1000; i++)
        {
            if (prime[i])
            {
                // duyet tat ca cac boi so cua i
                for (int j = i * i; j <= 10000001, j += i)
                {
                    prime[j] = 0; // j k con la so ngu8yen to nua
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (prime[i])
        {
            cout < prime[i] << " ";
        }
    }
}