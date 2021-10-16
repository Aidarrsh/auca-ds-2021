#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int f(string s)
{
    int cnt = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (isalpha(s[i]))
        {
            cnt += (int)(tolower(s[i]) - 96);
        }
    }
    return cnt;
}

int sumOfDigits(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s, s1;
    while (getline(cin, s) && getline(cin, s1))
    {
        int sSum = f(s);
        int s1Sum = f(s1);
        while (sSum > 9)
            sSum = sumOfDigits(sSum);
        while (s1Sum > 9)
            s1Sum = sumOfDigits(s1Sum);
        if (sSum > s1Sum)
            cout << fixed << setprecision(2) << 100 * (s1Sum * 1.0) / (sSum * 1.0) << " %\n";
        else
            cout << fixed << setprecision(2) << 100 * (sSum * 1.0) / (s1Sum * 1.0) << " %\n";
    }
}