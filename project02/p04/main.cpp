#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

struct f
{
    string DNA;
    int nInversions;

    f(string &s)
        : DNA(s)
    {
        int cnt = 0;
        for (int i = 0; i < sz(s); i++)
        {
            for (int j = i; j < sz(s); j++)
            {
                if (s[i] > s[j])
                {
                    cnt++;
                }
            }
        }
        nInversions = cnt;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;

        if (i)
        {
            cout << "\n";
        }

        vector<f> v;
        string s;

        for (int j = 0; j < m; j++)
        {
            cin >> s;
            v.emplace_back(s);
        }

        stable_sort(v.begin(), v.end(), [](const f &a, const f &b)
                    { return a.nInversions < b.nInversions; });
        for (int j = 0; j < sz(v); j++)
        {
            cout << v[j].DNA << "\n";
        }
    }
}