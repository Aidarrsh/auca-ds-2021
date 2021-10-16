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

    string s;
    bool ok = true;
    while (getline(cin, s))
    {
        int sz = s.size();
        for (auto i = 0; i < sz; i++)
        {
            if (s[i] == '"')
            {
                if (ok)
                {
                    cout << "``";
                }
                else
                {
                    cout << "''";
                }
                ok = !ok;
            }
            else
            {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}