#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, mod;
    while (cin >> n >> mod && (n != 0 && mod != 0))
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), [&](int &res, int &res2)
             {
                 int x = res % mod;
                 int y = res2 % mod;
                 int abs1 = abs(res);
                 int abs2 = abs(res2);

                 if (x == y)
                 {
                     if (abs1 % 2 == 1 && abs2 % 2 == 1)
                     {
                         return res > res2;
                     }
                     if (abs1 % 2 == 0 && abs2 % 2 == 0)
                     {
                         return res < res2;
                     }

                     return (abs1 % 2) > (abs2 % 2);
                 }
                 else
                 {
                     return x < y;
                 }
             });

        cout << n << " " << mod << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }
    cout << 0 << " " << 0 << "\n";
}
