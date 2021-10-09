#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000001

long long N[SIZE];

long long f(long long x)
{
    long long cnt = 1;
    while (x > 1)
    {
        if (x % 2 == 0)
        {
            x /= 2;
            cnt++;
        }
        else
        {
            x = 3 * x + 1;
            cnt++;
        }
    }
    return cnt;
}

long long findMax(long long a, long long b)
{
    long long Max = INT_MIN;
    long long st = min(a, b);
    long long end = max(a, b);
    for (long long i = st; i <= end; i++)
    {

        Max = max(Max, N[i]);
    }
    return Max;
}

int main()
{
    iostream::sync_with_stdio(false);

    for (long long i = 1; i < SIZE; i++)
    {
        N[i] = f(i);
    }

    long long a, b;
    while (cin >> a >> b)
    {

        cout << a << " " << b << " " << findMax(a, b) << "\n";
    }
}