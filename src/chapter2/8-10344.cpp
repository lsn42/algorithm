#include <iostream>
#include <cstring>

using namespace std;

int table[21];

int f(int n)
{
  if (table[n] == -1)
  {
    if (n == 1)
    {
      return 1;
    }
    else
    {
      int s = 0;
      for (int i = 1; i < n; ++i)
      {
        s += f(i)*f(n-i);
      }
      table[n] = s;
      return s;
    }
  }
  else
  {
    return table[n];
  }
}

int main()
{
  memset(table, -1, sizeof(table));
  int n;
  cin >> n;
  cout << f(n);
}