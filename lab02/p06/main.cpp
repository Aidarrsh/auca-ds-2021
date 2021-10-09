#include <bits/stdc++.h>

using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x, y, z, Case = 1, sum, Max, Min;
    cin >> n;
    while (n--)
    {
        sum = 0;
        cin >> x >> y >> z;
        Max = max(x, max(y, z));
        Min = min(x, min(y, z));
        sum = x + y +z ;
        cout << "Case " << Case++ << ": " << sum - Max - Min << "\n";
    }
}