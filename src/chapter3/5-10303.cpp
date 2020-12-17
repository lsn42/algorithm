#include <iostream>
using namespace std;
int main()
{
  int n, a[101][101], m[101][101];
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      cin >> a[i][j];
    }
  }
  for (int i = n-1; i >= 0; --i)
  {
    for (int j = 0; j <= i; ++j)
    {
      if (i < n-1)
      {
        m[i][j] = max(m[i+1][j], m[i+1][j+1])+a[i][j];
      }
      else
      {
        m[i][j] = a[i][j];
      }
    }
  }
  cout << m[0][0] << endl;
  int k = 0;
  cout << a[0][0];
  for (int i = 1; i < n; ++i)
  {
    if (m[i][k] <= m[i][k+1])
    {
      ++k;
    }
    cout << " " << a[i][k];
  }
}