#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
    x = x % 100;
    if (abs(x) < 10)
    {
        x = 0;
    }
    while (abs(x) >= 10)
    {
        x /= 10;
    }
    return x;
}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        int x = (y * 567 / 9 + 7492) * 235 / 47 - 498;
        x = f(x);
        cout << abs(x) << "\n";
    }
}