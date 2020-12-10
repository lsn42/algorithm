#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
  return a>b;
}

void f(int a[], int start, int end)
{
  int median;
  if (start == end)
  {
    return;
  }
  if ((end-start)%2) // even
  {
    median = (a[start+(end-start)/2]+a[start+(end-start)/2+1])/2;
  }
  // make_heap(a[start], a[start+(end-start)/2]);
}

int main()
{
  int n;
  vector<int> a;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  make_heap(a.begin(), a.end());
  for (int i = 0; i < n; ++i)
  {
    cout << a[i] << " ";
  }
}