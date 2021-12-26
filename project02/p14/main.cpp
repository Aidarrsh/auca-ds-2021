#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    vector<string> v;
    bool first = false;
    while (n != 0)
    {
        cin >> n;
        if (first && n != 0)
        {
            cout << "\n";
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.emplace_back(s);
        }
        stable_sort(begin(v), end(v), [](string a, string b)
                    {
                        if (a[0] != b[0])
                        {
                            return a < b;
                        }
                        else
                        {
                            return a[1] < b[1];
                        }
                    });

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
        v.clear();
        first = true;
        // cout <<"\n";
    }
}