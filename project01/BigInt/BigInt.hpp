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

bool operator>(BigInt a, BigInt b)
{
    if (a == b){
        return false;
    } else {
        if (a.mIsNegative != b.mIsNegative){
            if (a.mIsNegative){
                return false;
            } else {
                return true;
            }
        } else {
            if (a.mDigits.size() > b.mDigits.size()){
                return true;
            } else if (a.mDigits.size() < b.mDigits.size()) {
                return false;
            }
            else {
                auto ita = a.mDigits.begin();
                auto itb = b.mDigits.begin();
                while (ita != a.mDigits.end()){
                    if (*ita > *itb){
                        return true;
                    } else if (*ita < *itb){
                        return false;
                    } else {
                        ita++;
                        itb++;
                    }
                }
                return false;
            }
        }
    }
}

bool operator<( BigInt a, BigInt b) 
{
    if (a == b) {
        return false;
    } else if (a > b) {
        return false;
    } else {
        return true;
    }
}

bool operator>=(BigInt a, BigInt b)
{
    if (a == b) {
        return true;
    } else if (a > b){
        return true;
    } else {
        return false;
    }
}

bool operator<=(BigInt a, BigInt b)
{
    if (a == b) {
        return true;
    } else if (a < b){
        return true;
    } else {
        return false;
    }
}

bool operator!=(BigInt a, BigInt b)
{
    if (a == b){
        return false;
    } else {
        return true;
    }
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
    if (a < b){
        r.mIsNegative = true;
        std::swap(a,b);
    }

    if (a == b){
        r.mDigits.push_back(0);
        return r;
    }

    if (a.mIsNegative){
        r.mIsNegative = true;
        return a + b;
    }

    if (b.mIsNegative){
        r.mIsNegative = false;
        return a + b;
    }

    if (a.mIsNegative && b.mIsNegative){
        std::swap(a,b);
    }
    reverse(a.mDigits.begin(), a.mDigits.end());
    reverse(b.mDigits.begin(), b.mDigits.end());
    
    auto it1 = a.mDigits.begin();
    auto it2 = b.mDigits.begin();
    int carry = 0;
    while(it1 !=  a.mDigits.end() || it2 != b.mDigits.end()) {
        int sum = carry;
        carry = 0;
        if (it1 != a.mDigits.end()) {
            sum += *it1;
            if (*it1 == 0){
                sum += 10;
                carry --;
            }
            it1++;
        }

        if (it2 != b.mDigits.end()) {
            sum -= *it2;
            // if (*it2 == 0){
            //     sum -= 10;
            // }
            sum = abs(sum);
            it2 ++;
        }
        if (sum != 0 && (it1 != a.mDigits.end() || it2 != b.mDigits.end())){
            r.mDigits.push_back(sum % 10);
        }
    }
    reverse(r.mDigits.begin(), r.mDigits.end());
    return r;
}