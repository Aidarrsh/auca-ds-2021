#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
typedef long long ll;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n >> ws;

    vector<pair<int, string>> v;

    for (int i = 0; i < n; i++)
    {
        string s, s1;
        cin >> s >> s1;

        if (isalpha(s[0]))
        {
            v.emplace_back(stoi(s1), s);
        }
        else
        {
            v.emplace_back(stoi(s) /2 , s1);
        }
    }
    sort(begin(v), end(v));

    for (auto it : v)
    {
        cout << it.second << "\n";
    }
}