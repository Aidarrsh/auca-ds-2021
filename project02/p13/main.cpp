#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    vector<string> v;
    int maxLenght = 0;
    while (getline(cin, s))
    {
        if (s == "")
        {

            sort(begin(v), end(v), [](string a, string b)
                 {
                     reverse(begin(a), end(a));
                     reverse(begin(b), end(b));
                     return a < b;
                 });

            for (auto i : v)
            {
                cout.width(maxLenght);
                cout << i << "\n";
            }
            v.clear();
            maxLenght = 0;
            cout <<"\n";
        }
        else
        {
            if (s.length() > maxLenght)
            {
                maxLenght = s.length();
            }
            v.push_back(s);
        }
    }
    sort(begin(v), end(v), [](string a, string b)
         {
             reverse(begin(a), end(a));
             reverse(begin(b), end(b));
             return a < b;
         });

    for (auto i : v)
    {
        cout.width(maxLenght);
        cout << i << "\n";
    }
}