#include <bits/stdc++.h>

using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x, y, z;
    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> x;

        x *= -2;
        y = 1 - 4 * x;

        z = (-1 + sqrt(y)) / 2;

        cout << z << "\n";
    }
}