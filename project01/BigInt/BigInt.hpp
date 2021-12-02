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

BigInt operator+( BigInt a, BigInt b) 
{
    BigInt r;
    r.mDigits.clear();
    reverse(a.mDigits.begin(), a.mDigits.end());
    reverse(b.mDigits.begin(), b.mDigits.end());

    auto it1 = a.mDigits.begin();
    auto it2 = b.mDigits.begin();
    int carry = 0;
    while(it1 !=  a.mDigits.end() || it2 != b.mDigits.end() || carry != 0) {
        int sum = carry;
        if (it1 != a.mDigits.end()) {
            sum += *it1;
            it1++;
        }

        if (it2 != b.mDigits.end()) {
            sum += *it2;
            it2 ++;
        }

        r.mDigits.push_back(sum % 10);
        carry = sum / 10;
    }
    reverse(r.mDigits.begin(), r.mDigits.end());
    return r;
}

BigInt operator-(BigInt a, BigInt b)
{
    BigInt r;
    r.mDigits.clear();
    reverse(a.mDigits.begin(), a.mDigits.end());
    reverse(b.mDigits.begin(), b.mDigits.end());
    
    auto it1 = a.mDigits.begin();
    auto it2 = b.mDigits.begin();
    int carry = 0;
}

bool operator==(BigInt a, BigInt b)
{
    if (a.mDigits.size() == b.mDigits.size() && a.mIsNegative == b.mIsNegative)
    {
        auto ita = a.mDigits.begin();
        auto itb = b.mDigits.begin();
        while (ita != a.mDigits.end())
        {
            if (*ita == *itb) {
                ita++;
                itb++;
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}