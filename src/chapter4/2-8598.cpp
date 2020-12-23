#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
  char a[1000] = {0};
  bool five = false, zero = false;
  int n = 0, sum = 0;
  while ((a[n++] = getchar()) != '\n') {};
  --n;
  for (int i = 0; i < n; ++i)
  {
    if (a[i] == '5')
    {
      five = true;
    }
    else if (a[i] == '0')
    {
      zero = true;
    }
    sum += a[i] - '0';
  }
  if (!(five || zero))
  {
    cout << "impossible";
    return 0;
  }
  int min = -1;
  if (sum % 3 == 1)
  {
    for (int i = 0; i < n; ++i)
    {
      if ((a[i] - '0') % 3 == 1)
      {
        if (a[i] == '1')
        {
          a[i] = 0;
          --n;
          break;
        }
        else
        {
          if (!(min != -1 && a[i] < a[min]))
          {
            min = i;
          }
        }
      }
      if (i == n - 1 && min != -1)
      {
        a[min] = 0;
        --n;
      }
    }
    if (min == -1)
    {
      for (int j = 0; j < 2; ++j)
      {
        min = -1;
        for (int i = 0; i < n; ++i)
        {
          if ((a[i] - '0') % 3 == 2)
          {
            if (a[i] == '2')
            {
              a[i] = 0;
              --n;
              break;
            }
            else
            {
              if (!(min != -1 && a[i] < a[min]))
              {
                min = i;
              }
            }
          }
          if (i == n - 1)
          {
            a[min] = 0;
            --n;
          }
        }
      }
    }
  }
  else if (sum % 3 == 2)
  {
    for (int i = 0; i < n; ++i)
    {
      if ((a[i] - '0') % 3 == 2)
      {
        if (a[i] == '2')
        {
          a[i] = 0;
          --n;
          break;
        }
        else
        {
          if (!(min != -1 && a[i] < a[min]))
          {
            min = i;
          }
        }
      }
      if (i == n - 1 && min != -1)
      {
        a[min] = 0;
        --n;
      }
    }
    if (min == -1)
    {
      for (int j = 0; j < 2; ++j)
      {
        min = -1;
        for (int i = 0; i < n; ++i)
        {
          if ((a[i] - '0') % 3 == 1)
          {
            if (a[i] == '1')
            {
              a[i] = 0;
              --n;
              break;
            }
            else
            {
              if (!(min != -1 && a[i] < a[min]))
              {
                min = i;
              }
            }
          }
          if (i == n - 1)
          {
            a[min] = 0;
            --n;
          }
        }
      }
    }
  }
  if (n > 0)
  {
    sort(a, a + 1000, greater<int>());
    if (!zero)
    {
      for (int i = 0; i < n; ++i)
      {
        if (a[i] == '5')
        {
          a[i] = 0;
          --n;
          break;
        }
      }
      sort(a, a + 1000, greater<int>());
      a[n++] = '5';
    }
    for (int i = 0; i < n; ++i)
    {
      cout << a[i];
    }
  }
  else
  {
    cout << "impossible";
  }
}