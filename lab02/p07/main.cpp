#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b, ans;
    while (cin >>a >>b){
        if (a == -1 && b == -1){
            return 0;
        }
        if (b > a){
            swap (b, a);
        }
        ans = a - b;
        if (ans > 50){
            ans = 100 -ans;
            cout <<ans <<endl;
        } else {
            cout <<ans << endl;
        }
    }
}