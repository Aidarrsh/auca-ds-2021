#include <bits/stdc++.h>

using namespace std;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, x, cnt, y = 1;
    while (cin >> x >> n && x != 0 && n != 0)
    {
        cnt = 0;
        x -= n;
        if (x > 0)
        {
            for (cnt = 1; cnt <= 27; cnt++)
            {
                if (n * cnt - x >= 0)
                    break;
            }
        }
        cout << "Case " << y++ << ": ";
        if (cnt > 26)
            cout << "impossible\n";
        else
            cout << cnt << "\n";
    }
}