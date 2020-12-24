#include <cstdio>

using namespace std;
int l[10000][10000];

int main()
{
  char x[10000] = {0}, y[10000] = {0};
  int n = 0, m = 0, max_end = 0, max_length = 0;
  scanf("%s%s", x, y);
  while (x[++n] != 0) {};
  while (y[++m] != 0) {};

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (x[i] == y[j])
      {
        if (i != 0 && j != 0)
        {
          l[i][j] = l[i - 1][j - 1] + 1;
        }
        else
        {
          l[i][j] = 1;
        }
      }
      else
      {
        l[i][j] = 0;
      }
      if (l[i][j] > max_length)
      {
        max_length = l[i][j];
        max_end = i;
      }
    }
  }
  x[max_end + 1] = 0;
  printf("%d\n%s", max_length, x + max_end - max_length + 1);
}