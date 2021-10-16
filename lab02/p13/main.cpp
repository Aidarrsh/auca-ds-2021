#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int b, n, x, gB, tB, money;
    while (cin >> b >> n && b != 0 && n != 0)
    {
        vector<int> v;
        for (int i = 0; i < b; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            cin >> gB >> tB >> money;
            v[gB - 1] -= money;
            v[tB - 1] += money;
        }
        for (int i = 0; i < sz(v); i++)
        {
            if (v[i] < 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "S\n";
        else
            cout << "N\n";
    }
}