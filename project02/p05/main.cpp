#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int value, ascii;

    Pair(const int &v, const int &a)
        : value(v), ascii(a)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    bool first = true;
    ;
    while (getline(cin, s))
    {
        vector<Pair> v;
        vector<int> num(128, 0);
        if (!first)
        {
            cout << "\n";
        }
        first = false;
        for (auto i : s)
        {
            num[i]++;
        }

        for (int i = 0; i < sz(num); i++)
        {
            if (num[i] != 0)
            {
                v.emplace_back(num[i], i);
            }
        }
        sort(begin(v), end(v), [](const Pair &a, const Pair &b)
             {
                 if (a.value == b.value)
                 {
                     return a.ascii > b.ascii;
                 }
                 return a.value < b.value;
             });

        for (int i = 0; i < sz(v); i++)
        {
            cout << v[i].ascii << " " << v[i].value << "\n";
        }
    }
}