#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b)
{
    return a%b == 0? b: gcd(b, a%b);
}
long long f(int i, int x, int n)
{
    long long result = i;
    for (; n > 0; --n)
    {
        result *= 10;
        result += x;
    }
    return result;
}

int main()
{
    string input;
    long long a = 0, b = 0, c = 0, d = 0;
    cin >> input;
    int p = input.find('.'), lb = input.find('(');
    if (p == (int)string::npos)
    {
        cout << input << " " << 1;
    }
    else
    {
        // number before point
        for (int j = 0; j < p; ++j)
        {
            a *= 10;
            a += input[j] - '0';
        }
        // number after point
        if (lb == (int)string::npos)
        {
            // no brackets, only number between point to end
            for (int j = p+1; j < (int)input.length(); ++j)
            {
                a *= 10;
                a += input[j] - '0';
            }
            b = f(1, 0, (int)input.length()-p-1);
        }
        else
        {
            // with bracket, number between point to end and the loop
            for (int j = p+1; j < lb; ++j)
            {
                a *= 10;
                a += input[j] - '0';
            }
            b = f(1, 0, lb-p-1);
        
            for (int j = lb+1; j < (int)input.length()-1; ++j)
            {
                c *= 10;
                c += input[j] - '0';
            }
            if (c != 0)
            {
                d = f(0, 9, (int)input.length()-lb-2);
                a = a*d+c;
                b = b*d;
            }
        }
        long long g = gcd(a, b);
        a /= g;
        b /= g;
        cout << a << " " << b;
    }
}