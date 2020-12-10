#include <iostream>
#include <cstring>

using namespace std;

int fm(int a[], int start, int middle, int end)
{
  int b[10000], ll = 0;
  int l = start, r = middle, c = 0;
  for (int i = start; i < end; ++i)
  {
    if (a[l] > a[r])
    {
      c += middle-l;
      ++r;
      b[ll] = a[r];
      ++ll;
    }
    else
    {
      ++l;
      b[ll] = a[l];
      ++ll;
    }
  }
  for (int i = start; i < end; ++i)
  {
    a[i] = b[start-i];
  }
  return c;
}
int f(int a[], int start, int end)
{
  int c = 0;
  if (start < end)
  {
    int m = (start+end)/2;
    c += f(a, start, m);
    c += f(a, m+1, end);
    c += fm(a, start, m, end);
  }
  return c;
}

int main()
{
  int n, a[10000];
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  cout << f(a, 0, n);
}