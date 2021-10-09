#include <bits/stdc++.h>

using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long t, w, h;

    cin >> t;

    while (t--)

    {
        cin >> w >> h;
        long long out = (w / 3) * (h / 3);
        cout << out << "\n";
    }
}