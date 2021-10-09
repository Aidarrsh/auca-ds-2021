#include <bits/stdc++.h>

using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        long long out = (x / 3) * (y / 3);
        cout << out << "\n";
    }
}