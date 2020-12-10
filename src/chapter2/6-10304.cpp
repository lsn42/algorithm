#include <iostream>
#include <cstring>

using namespace std;

int f(int n, int k)
{
  if (n > 3)
  {
    if (n%2 && k < 3)
    {
      return 0;
    }
    else if (!n%2 && k < 2)
    {
      return 0;
    }
    else
    {
      return (k-2)*f(n-1, k)+(k-1)*f(n-2, k);
    }
  }
  else if (n == 3)
  {
    if (k < 3)
    {
      return 0;
    }
    else
    {
      return k*(k-1)*(k-2);
    }
  }
  else if (n == 2)
  {
    if (k < 2)
    {
      return 0;
    }
    else
    {
      return k*(k-1);
    }
  }
  else if (n == 1)
  {
    return k;
  }
  return 0;
}

int main()
{
  int n, k;
  cin >> n >> k;
  cout << f(n, k);
}