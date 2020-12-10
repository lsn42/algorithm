#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double r[100][4], x[200], y[200], s = 0;
    bool o[200][200] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf%lf%lf",&r[i][0], &r[i][1], &r[i][2], &r[i][3]);
        x[2*i] = r[i][0];
        y[2*i] = r[i][1];
        x[2*i+1] = r[i][2];
        y[2*i+1] = r[i][3];
    }
    sort(x, x+2*n);
    sort(y, y+2*n);

    for (int i = 0; i < n; ++i)
    {
        int xp = 0, yp = 0;
        while (x[xp] < r[i][0] && xp < 2*n)
        {
            ++xp;
        }
        while (y[yp] < r[i][1] && yp < 2*n)
        {
            ++yp;
        }
        while (x[xp] < r[i][2] && xp < 2*n)
        {
            int t_yp = yp;
            while (y[t_yp] < r[i][3] && t_yp < 2*n)
            {
                o[xp][t_yp] = true;
                ++t_yp;
            }
            ++xp;
        }
    }
    for (int i = 0; i < 2*n-1; ++i)
    {
        for (int j = 0; j < 2*n-1; ++j)
        {
            if (o[i][j])
            {
                s += (x[i+1]-x[i])*(y[j+1]-y[j]);
            }
        }
    }
    
    printf("%.2f", s);
}