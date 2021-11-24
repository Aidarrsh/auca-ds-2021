#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <cstdint>
#include <iostream>

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

    const std::vector<int> getVector()
    {
        return mDigits;
    }

    const bool getBool()
    {
        return mIsNegative;
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

BigInt operator+(const BigInt &a, const BigInt &b)
{
    vector <int> x = a.getVector();
    vector <int> y = b.getVector();
    if (x.size() < y.size()){
        x.swap(y);
    }
    int diff;
    diff = x.size() - y.size();
    reverse(y.begin(), y.end());
    for (int i = 0; i < y.size(); i++){
        y.push_back(0);
    }
    reverse(y.begin(),y.end());
    for (int i = 0; i < x.size(); i ++){
        for (int j = 0; j < y.size(); j ++){
            
        }
    }
}