#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int w, h;
    while (cin >> h >> w)
    {
        char d[h + 1][w + 1];
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> d[i][j];
            }
        }
        int sum = 0, f = 0, s = 0;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                char l = d[i][j];
                if (l != '.')
                {
                    if (f == 0)
                        f = j;
                    else if (s == 0)
                        s = j;
                }
                if (f > 0 && s > 0)
                {
                    sum += s - f;
                    s = 0;
                    f = 0;
                }
            }
        }
        cout << sum << "\n";
    }
}