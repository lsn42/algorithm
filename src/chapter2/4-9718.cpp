#include <iostream>

using namespace std;

int solve2(int n)
{
  int c = 0;
  if (n == 1)
  {
    return 1;
  }
  for (int i = 2; i <= n; ++i)
  {
    if (n%i == 0)
    {
      c += solve2(n/i);
    }
  }
  return c;
}

int main()
{
  int n;
  cin >> n;
  cout << solve2(n);
}