#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        int n;
        cin >> n;
        vector<int> r, b;
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            char color = s.back();
            s.pop_back();
            int value = stoi(s);

            if (color == 'R')
            {
                r.emplace_back(value);
            }
            else
            {
                b.emplace_back(value);
            }
        }
        sort(begin(r), end(r));
        sort(begin(b), end(b));

        int sum = 0;
        while (r.size() && b.size())
        {
            sum += r.back() + b.back();
            sum -= 2;
            r.pop_back();
            b.pop_back();
        }
        cout << "Case #" << test << ": " << sum << "\n";
    }
}