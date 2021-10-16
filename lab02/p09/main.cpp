#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n, x;
    cin >> t;
    while (t--)
    {
        int Max = 0, Min = 101;
        cin >> n;
        while (n--)
        {
            cin >> x;
            Max = max(Max, x);
            Min = min(Min, x);
        }
        cout << (Max - Min) * 2 << "\n";
    }
}