#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n, x;
    cin >> n;
    cout << "Lumberjacks:\n";
    while (n--)
    {
        vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i < 10; i++)
        {
            if (v[i - 1] >= v[i])
            {
                cnt0++;
            }
        }
        for (int i = 1; i < 10; i++)
        {
            if (v[i - 1] <= v[i])
            {
                cnt1++;
            }
        }
        if (cnt0 == 9 || cnt1 == 9)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
}