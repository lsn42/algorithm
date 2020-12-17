#include <iostream>
#include <cmath>
using namespace std;
int a[1000000] = {1};
int f1(int n)
{
  return n>1?pow(2, (int)log2(n)):1;
}
int f2(int n, int m)
{
  for (int i = 1; i <= n; ++i)
  {
    a[i] = (a[i-1]+m-1)%i+1;
  }
  return a[n];
}
int main()
{
  int n, m;
  cin >> n >> m;
  cout << f1(n) << " " << f2(n, m);
}