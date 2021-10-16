#include <bits/stdc++.h>

template <typename C>

int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

string f(string s)
{
    int sz = s.size(), cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        cnt += (int)(s[i] - 48);
    }
    return to_string(cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    while (cin >> s && s != "0")
    {
        while (s.size() > 1)
            s = f(s);
        cout << s << "\n";
    }
}