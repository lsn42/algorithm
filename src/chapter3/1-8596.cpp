#include <iostream>
using namespace std;
short l[1000];
int main()
{
  short n, a[1000];
  cin >> n;
  while (n != 0)
  {
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
      l[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
      int max = 0;
      for (int j = 0; j < i; ++j)
      {
        if (a[i] >= a[j] && l[j] >= l[max])
        {
          l[i] = l[j] + 1;
          max = j;
        }
      }
    }
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
      if (l[i] > l[max])
      {
        max = i;
      }
    }
    cout << l[max] + 1 << endl;
    cin >> n;
  }
}