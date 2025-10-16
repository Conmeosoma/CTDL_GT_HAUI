#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
bool Snt(int z)
{
  if (z == 2)
    return true;
  else if (z % 2 == 0 || z <= 1)
    return false;
  for (int i = 3; i <= sqrt(z); i += 2)
  {
    if (z % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int a[100];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (Snt(a[i]))
    {
      cout << a[i] << " ";
    }
  }
}