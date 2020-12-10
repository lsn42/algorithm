#include <iostream>

using namespace std;
bool money(int n, int count)
{
    return count > 0? (n-1)%5 == 0? money((n-1)*4/5, count-1): false: true;
}
int main()
{
    int n, p = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        if (money(i, 5))
        {
            cout << i << " ";
            ++p;
        }
    }
    if (p == 0)
    {
        cout << "impossible";
    }
}