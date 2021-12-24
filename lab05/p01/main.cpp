#include "../../au/algol.hpp"
#include <iostream>
#include "VecInt.hpp"
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

void p01()
{
    cout << "The size of array: ";
    int n;
    cin >> n;

    VecInt v(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    printVecInt(v);
    auReverse(v.begin(), v.end());
    printVecInt(v);
}

void p02()
{
    // vector <int> v;
    VecInt v;

    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    printVecInt(v);
    auReverse(v.begin(), v.end());
    // auReverse(v.data, v.data + v.sz); functions begin(), end() inlined
    printVecInt(v);
}

int main()
{
    //p01();
    p02();
}
