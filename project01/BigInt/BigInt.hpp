#pragma once
#include <vector>
#include <iosfwd>

class BigInt {
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, BigInt &x);
    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt ()
        : mIsNegative(false) 
    {
        mDigits.push_back(0);
    }

    BigInt (int n)
    {
        if (n < 0){
            mIsNegative = true;
            n = -n;
        } else {
            mIsNegative = false;
        }

        while (n){
        int temp = n%10;
        mDigits.push_back(temp);
        n /= 10;
        }

        reverse(mDigits.begin(), mDigits.end());
    }
   
};

inline
std::ostream &operator<<(std::ostream &out, const BigInt &x) 
{
    if (x.mIsNegative){
        out << '-';
    }

    for(auto digit: x.mDigits) {
        out << digit;
    }
    return out;
}