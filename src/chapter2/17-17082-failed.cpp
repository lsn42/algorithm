#include <iostream>
using namespace std;
int t(int x[], int y[], int k, int xs, int xe, int ys, int ye)
{
  int xm = (xs+xe)/2, ym = (ys+ye)/2, hl = xm-xs+ym-ys+2;
  if (xs > xe) return y[ys+k-1];
  if (ys > ye) return x[xs+k-1];
  return
  x[xm]<y[ym]?
    k<hl?
      t(x, y, k, xs, xe, ys, ym):
      t(x, y, k-xm+xs-1, xm, xe, ys, ye):
    k<hl?
      t(x, y, k, xs, xm, ys, ye):
      t(x, y, k-ym+ys-1, xs, xe, ym, ye);
}
int main()
{
  int m, n, k, x[100001], y[100001];
  cin >> m >> n >> k;
  for (int i = 0; i < m; ++i)
  {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i)
  {
    cin >> y[i];
  }
  cout << t(x, y, k, 0, m, 0, n);
}