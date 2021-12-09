#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;

struct f
{
    string job;
    int price;

    f(string &j, int &p)
    {
        job = j;
        price = p;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int m, n, price;
    string job, text;
    cin >> m >> n;

    vector<f> v;

    while (m != 0)
    {
        cin >> job >> price;
        v.emplace_back(job, price);
        m--;
    }

    while (n != 0)
    {
        int sum = 0;
        while (cin >> text && text != ".")
        {
            for (auto it : v)
            {
                if (it.job == text)
                {
                    sum += it.price;
                }
            }
        }
        cout << sum << "\n";
        n--;
    }
}
