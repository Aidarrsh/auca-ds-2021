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
        sort(v.begin(), v.end(), [&](int &value1, int &value2)
             {
                 int a = value1 % mod;
                 int b = value2 % mod;
                 int absValue1 = abs(value1);
                 int absValue2 = abs(value2);

                 if (a == b)
                 {
                     if (absValue1 % 2 == 1 && absValue2 % 2 == 1)
                     {
                         return value1 > value2;
                     }
                     if (absValue1 % 2 == 0 && absValue2 % 2 == 0)
                     {
                         return value1 < value2;
                     }

                     return (absValue1 % 2) > (absValue2 % 2);
                 }
                 else
                 {
                     return a < b;
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
