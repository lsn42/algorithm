#include <cmath>
#include <iostream>

using namespace std;
long long f(int n) { return n > 2 ? n * f(n - 1) : n; }
int main()
{
  int n;
  long long r1 = 1, r2 = 1;
  cin >> n;
  if (n > 4)
  {
    int i = 2, j = n;
    for (; j >= i; ++i)
    {
      j -= i;
    }
    r1 = f(j / (i - 2) + i) / (i - j % (i - 2));
    switch (n % 3)
    {
      case 0:
        {
          r2 = pow(3, n / 3);
          break;
        }
      case 1:
        {
          r2 = 4 * pow(3, (n - 4) / 3);
          break;
        }
      case 2:
        {
          r2 = 2 * pow(3, ((n - 2) / 3));
        }
    }
  }
  else
  {
    r1 = n > 2 ? n - 1 : n;
    r2 = n;
  }
  cout << r1 << " " << r2;
}