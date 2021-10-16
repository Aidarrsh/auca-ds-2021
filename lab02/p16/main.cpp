#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

string hb[16] = {
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "you",
    "Happy",
    "birthday",
    "to",
    "Rujia",
    "Happy",
    "birthday",
    "to",
    "you",
};

int main()

{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    string s;
    string v[t];
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        v[i] = s;
    }
    int w = 0;
    for (int i = 0; i < t; i++)
    {
        cout << v[i] << ": " << hb[w % 16] << "\n";
        w++;
        if (i == t - 1)
        {
            if (w % 16 != 0)
            {
                int j = 0;
                while (w % 16 > 0)
                {
                    cout << v[j % t] << ": " << hb[w % 16] << "\n";
                    j++;
                    w++;
                }
            }
        }
    }
}