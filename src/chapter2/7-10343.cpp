#include <iostream>
#include <cstring>

using namespace std;

int t[21] = {-1};
int f(int n)
{
  int c = 0;
  if (n < 3)
  {
    return 1;
  }
  if (t[n] != -1)
  {
    return t[n];
  }
  else
  {
    for (int i = 2; i < n; ++i)
    {
      c += f(i)*f(n+1-i);
    }
    t[n] = c;
  }
  return c;
}

int main()
{
  memset(t, -1, sizeof(t));
  int n;
  cin >> n;
  if (n < 3)
  {
    cout << "No answer";
  }
  else
  {
    cout << f(n);
  }
}