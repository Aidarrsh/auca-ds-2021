#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, cnt = 0;
    string str, str2;
    while (cin >> n)
    {
        if (cnt)
            cout << "\n";

        map<string, int> db;
        vector<string> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        int sum, g;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            cin >> str >> sum >> g;

            if (g)
                a = sum / g;

            for (int j = 0; j < g; j++)
            {
                cin >> str2;
                db[str2] += a;
                db[str] -= a;
            }
        }

        for (auto n : v)
            cout << n << " " << db[n] << "\n";

        cnt++;
    }
}
