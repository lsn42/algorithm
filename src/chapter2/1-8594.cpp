#include <iostream>

using namespace std;

bool find_same(char list[], int k, int i)
{
    for (;k < i; ++k)
    {
        if (list[i] == list[k])
        {
            return true;
        }
    }
    return false;
}

int PermExcludeSame(char list[], int k, int m)
{
    int count = 0;
    if (k == m)
    {
        for (int i = 0; i <= m; ++i)
        {
            cout << list[i];
        }
        cout << endl;
        ++count;
    }
    else
    {
        for (int i = k; i <= m; ++i)
        {
            if (find_same(list, k, i))
            {
                continue;
            }
            swap(list[k], list[i]);
            count += PermExcludeSame(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
    return count;
}

int main()
{
    int n;
    char a[15] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << PermExcludeSame(a, 0, n-1);
}