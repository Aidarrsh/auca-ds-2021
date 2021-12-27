#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    vector<string> att;

    getline(cin, s);
    stringstream ss(s);
    while (ss >> s)
    {
        att.push_back(s);
    }

    int n;
    cin >> n;
    vector<vector<string>> songs(n);
    for (int i = 0; i < n; i++)
    {
        vector<string> temp(sz(att));
        for (int j = 0; j < sz(att); j++)
        {
            cin >> temp[j];
        }
        songs[i] = temp;
    }
    int m;
    cin >> m;
    string sortSongs;
    for (int i = 0; i < m; i++)
    {
        if (i)
            cout << "\n";

        cin >> sortSongs;

        auto it = find(att.begin(), att.end(), sortSongs);
        int x = it - att.begin();

        stable_sort(songs.begin(), songs.end(), [x](vector<string> a, vector<string> b)
                    { return a[x] < b[x]; });

        for (int j = 0; j < sz(att); j++)
        {
            if (j)
            {
                cout << " ";
            }
            cout << att[j];
        }

        cout << "\n";

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < sz(att); k++)
            {
                if (k)
                {
                    cout << " ";
                }
                cout << songs[j][k];
            }
            cout << "\n";
        }
    }
}