#include "../../au/algol.hpp"
#include "VecInt.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void printVecInt(const VecInt &v)
{
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    VecInt v;

    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    VecInt w;
    w = v;
    reverse(w.begin(), w.end());

    cout << (w == v ? "palindrome" : "not a palindrome") << endl;
}
