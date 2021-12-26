#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
typedef long long ll;

ll getClassValue(string s)
{
    replace(begin(s), end(s), '-', ' ');
    stringstream ss(s);

    string out = "", temp;
    while (ss >> temp)
    {
        if (temp == "upper")
        {
            out += "3";
        }
        if (temp == "middle")
        {
            out += "2";
        }
        if (temp == "lower")
        {
            out += "1";
        }
    }
    reverse(begin(out), end(out));
    while (sz(out) < 10)
    {
        out += "2";
    }
    stringstream s1(out);
    ll res;
    s1 >> res;
    return res;
}

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        vector<pair<string, string>> v;
        for (int j = 0; j < n; j++)
        {
            string s, s1, s2;
            cin >> s >> s1 >> s2;
            s.pop_back();

            v.emplace_back(s, s1);
        }

        stable_sort(begin(v), end(v), [](const pair<string, string> &a, const pair<string, string> &b)
             {
            if (getClassValue(a.second) > getClassValue(b.second))
            {
                return true;
            }
            else if (getClassValue(a.second) == getClassValue(b.second))
            {
                if (a.first < b.first)
                {
                    return true;
                }
            }
                return false; });

        for (auto it : v)
        {
            cout << it.first << "\n";
        }
        cout << "==============================\n";
    }
}