#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    vector<string> v;
    // bool first = false;
    while (cin >> n)
    {
        
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        stable_sort(begin(v), end(v), [](string a, string b)
                    {
                        if (a[0] != b[0])
                        {
                            return a[0] < b[0];
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
        // first = true;
        // if (first && n != 0)
        // {
        //     cout << "\n";
        // }
    }
}