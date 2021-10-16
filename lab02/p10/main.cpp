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
    for (int c = 1; c <= t; c++)
    {
        int h = 0, l = 0, x1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (i == 0)
            {
                x1 = x;
                continue;
            }
            else
            {
                if (x > x1)
                    h++;
                if (x < x1)
                    l++;
                x1 = x;
            }
        }
        cout << "Case " << c << ": " << h << " " << l << "\n";
    }
}