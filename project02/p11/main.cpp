#include <bits/stdc++.h>

using namespace std;
int main()
{
    int r, c;

    while (cin >> r && cin >> c && r != 0 && c != 0)
    {
        vector<string> v(c, "");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                char n;
                cin >> n;

                v[j].push_back(n);
            }
        }

        stable_sort(begin(v), end(v), [](string a, string b)
                    {
                        for (auto &e : a)
                        {
                            e = tolower(e);
                        }

                        for (auto &e : b)
                        {
                            e = tolower(e);
                        }

                        return a < b;
                    });

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << v[j][i];
            }
            cout << "\n";
        }

        cout << "\n";
    }
}