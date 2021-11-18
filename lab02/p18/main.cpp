#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int k, m, cn, r;
    string c;
    while (cin >> k && k != 0)
    {
        cin >> m;

        map<string, int> sc;

        for (int i = 0; i < k; i++)
        {
            cin >> c;
            sc[c] = 1;
        }

        int res = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> cn >> r;

            string ct;
            int cnt = 0;
            for (int i = 0; i < cn; i++)
            {
                cin >> ct;
                if (sc[ct])
                {
                    cnt++;
                }
            }
            if (cnt >= r)
                res++;
        }

        cout << (res >= m ? "yes" : "no")
             << "\n";
    }
}
