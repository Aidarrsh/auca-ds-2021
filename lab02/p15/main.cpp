#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()

{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int x, Max = -1;

        string s;
        vector<pair<int, string>> v;
        for (int i = 0; i < 10; i++)
        {
            cin >> s >> x;
            Max = max(Max, x);
            v.push_back(make_pair(x, s));
        }
        cout << "Case #" << c << ":\n";
        for (int i = 0; i < 10; i++)
        {
            if (v[i].first == Max)
                cout << v[i].second << "\n";
        }
    }
}