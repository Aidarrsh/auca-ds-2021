#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <cstdint>
#include <iostream>

class BigInt {
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, BigInt &x);
    

public:
    std::vector<int> mDigits;
    bool mIsNegative;
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

    BigInt (std::string str){
        mIsNegative = false;
        for (auto num : str){
            if (num == '-'){
                mIsNegative = true;
            } else if (isdigit(num)){
                mDigits.push_back((int) num -48);
            } else if (isalpha(num)){
                throw std::runtime_error("Input must be integer");
            }
        }
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

BigInt operator+( BigInt b1, BigInt b2) 
{
    BigInt r;
    r.mDigits.clear();
    reverse(b1.mDigits.begin(), b1.mDigits.end());
    reverse(b2.mDigits.begin(), b2.mDigits.end());

    auto it1 = b1.mDigits.begin();
    auto it2 = b2.mDigits.begin();
    int cur = 0;
    while(it1 !=  b1.mDigits.end() || it2 != b2.mDigits.end() || cur != 0) {
        int sum = cur;
        if (it1 != b1.mDigits.end()) {
            sum += *it1;
            it1++;
        }

        if (it2 != b2.mDigits.end()) {
            sum += *it2;
            it2 ++;
        }

        r.mDigits.push_back(sum % 10);
        cur = sum / 10;
    }
    reverse(r.mDigits.begin(), r.mDigits.end());
    return r;
}