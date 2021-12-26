#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char letter;
    int count;

    Freq(char mLetter, int mCnt)

        : letter(mLetter), count(mCnt)
    {
    }
};

int main()
{

    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int test = 1; test <= t; test++)
    {

        int r, c , m , n;
        cin >> r >> c >> m >> n;
        vector<Freq> v;
        vector<int> numbers(200);

        for (int i = 0; i < r; i++)
        {
            string str;
            cin >> str;

            for (auto e : str)
            {
                numbers[e]++;
            }
        }

        for (int i = 0; i < sz(numbers); i++)
        {
            if (numbers[i] != 0)
            {
                v.push_back(Freq((char)i, numbers[i]));
            }
        }
        sort(begin(v), end(v), [](const Freq &a, const Freq &b)
             { return a.count < b.count; });
        int mx = v[v.size() - 1].count;

        int ans = m * mx;

        for (int i = 0; i < sz(v) - 1; i++)
        {
            if (v[i].count == mx)
            {
                ans += m * mx;
            }
            else
            {
                ans += n * v[i].count;
            }
        }
        cout << "Case " << test << ": " << ans << "\n";
    }
}