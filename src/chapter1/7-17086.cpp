#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, i = 0;
    char a[10] = {0};
    scanf("%d", &n);
    scanf("%s", a);
    sort(a, a+n);
    do
    {
        i++;
        printf("%d %s", i, a);
        printf("\n");
    } while(next_permutation(a, a+n));
}