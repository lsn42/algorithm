#include <iostream>
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
using namespace std;

main()
{
    int n, r[100000], s = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> r[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int lp = i, rp = i, m = r[i];
        while (m > 0)
        {
            while (lp > 0)
            {
                if (lp > 0 && m <= r[lp-1])
                {
                    --lp;
                }
                else
                {
                    break;
                }
            }
            while (rp < n)
            {
                if (rp < n-1 && m <= r[rp+1])
                {
                    ++rp;
                }
                else
                {
                    break;
                }
            }
            s = max(s, (rp-lp+1)*m);
            m = min(lp>0?r[lp-1]:0, rp<n-1?r[rp+1]:0);
        }
    }
    cout << s << endl;
}