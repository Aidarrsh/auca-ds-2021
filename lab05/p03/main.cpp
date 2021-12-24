#include "../../au/algol.hpp"
#include "VecInt.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVecInt(const VecInt &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

VecInt getFirstN(const VecInt &v, size_t n)
{
    VecInt res;

    size_t lim = min(v.size(), n);
    for (size_t i = 0; i < lim; ++i)
    {
        res.push_back(v[i]);
    }

    return res;
}

void p00()
{
    cout << "----p00----" << endl;
    VecInt::numOfCopies = 0;

    VecInt v = {1, 2, 3, 4, 5, 6, 7};

    VecInt w = {1, 2};

    w = getFirstN(v, 5); // result of getFirstN(v,5) is rvalue (exists shortly)

    cout << "w.size() = " << w.size() << endl;

    cout << "number of copies: " << VecInt::numOfCopies << endl;
}

void p01()
{
    cout << "----p01----" << endl;
    VecInt::numOfCopies = 0;

    VecInt v1 = {1, 2, 3};
    VecInt v2 = {4, 5, 6, 7, 8, 9, 10};

    swap(v1, v2);

    cout << "number of copies: " << VecInt::numOfCopies << endl;
}

void p02()
{
    cout << "----p02----" << endl;
    VecInt::numOfCopies = 0;

    vector<VecInt> v;
    v.reserve(4);
    v.emplace_back(100);
    v.emplace_back(200);
    v.emplace_back(300);

    VecInt w(400);
    v.insert(begin(v), w);

    cout << "number of copies: " << VecInt::numOfCopies << endl;
}

int main()
{
    //p00();
    //p01();
    p02();
}
