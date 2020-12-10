#include <iostream>

using namespace std;

int main()
{
    int n, a[10000], length = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    int i = n-1, j = n-1;
    while (j > 0 && i > -1)
    {
        --(a[i] <= a[j]?i:j);
        length = max(length, j-i);
    }
    cout << length;
}