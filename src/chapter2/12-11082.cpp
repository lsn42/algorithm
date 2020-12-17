#include <iostream>
#include <cstring>
using namespace std;
int a[21];
int t(int n)
{
  if (n < 2)
  {
    return 1;
  }
  else
  {
    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
      if (a[i] == -1)
      {
        a[i] = t(i);
      }
      if (a[n-i] == -1)
      {
        a[n-i] = t(n-i);
      }
      sum += a[i]*a[n-i];
    }
    return sum;
  }
}
int main()
{
  memset(a, -1, sizeof(a));
  int n;
  cin >> n;
  cout << t(n);
}