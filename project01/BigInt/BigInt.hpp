#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <cstdint>
#include <iostream>

class BigInt
{
    // friend BigInt operator+(const BigInt &a, const BigInt &b);
    // friend BigInt operator*(const BigInt &a, const BigInt &b);
    // friend BigInt operator-(const BigInt &a, const BigInt &b);
    // friend bool operator==(const BigInt &a, const BigInt &b);
    // friend bool operator>(const BigInt &a, const BigInt &b);
    // friend bool operator!=(const BigInt &a, const BigInt &b);
    // friend bool operator<(const BigInt &a, const BigInt &b);
    // friend bool operator<=(const BigInt &a, const BigInt &b);

public:
    std::vector<int> mDigits;
    bool mIsNegative;
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(int n)
    {
        if (n < 0)
        {
            mIsNegative = true;
            n = -n;
        }
        else
        {
            mIsNegative = false;
        }

        while (n)
        {
            int temp = n % 10;
            mDigits.push_back(temp);
            n /= 10;
        }

        reverse(mDigits.begin(), mDigits.end());
    }

    BigInt(std::string str)
    {
        mIsNegative = false;
        for (auto num : str)
        {
            if (num == '-')
            {
                mIsNegative = true;
            }
            else if (isdigit(num))
            {
                mDigits.push_back((int)num - 48);
            }
            else if (isalpha(num))
            {
                throw std::runtime_error("Input must be integer");
            }
        }
    }

    static bool bigger(BigInt a, BigInt b)
    {
        if (equal(a,b))
        {
            return false;
        }
        else
        {
            if (a.mIsNegative != b.mIsNegative)
            {
                if (a.mIsNegative)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                auto it1 = a.mDigits.begin();
                auto it2 = b.mDigits.begin();
                if (a.mIsNegative)
                {
                    if (a.mDigits.size() > b.mDigits.size())
                    {
                        return false;
                    }
                    else if (a.mDigits.size() < b.mDigits.size())
                    {
                        return true;
                    }
                    else
                    {
                        while (it1 != a.mDigits.end())
                        {
                            if (*it1 < *it2)
                            {
                                return true;
                            }
                            else if (*it1 > *it2)
                            {
                                return false;
                            }
                            else
                            {
                                it1++;
                                it2++;
                            }
                        }
                        return false;
                    }
                }
                else
                {
                    if (a.mDigits.size() > b.mDigits.size())
                    {
                        return true;
                    }
                    else if (a.mDigits.size() < b.mDigits.size())
                    {
                        return false;
                    }
                    else
                    {
                        while (it1 != a.mDigits.end())
                        {
                            if (*it1 > *it2)
                            {
                                return true;
                            }
                            else if (*it1 < *it2)
                            {
                                return false;
                            }
                            else
                            {
                                it1++;
                                it2++;
                            }
                        }
                        return false;
                    }
                }
            }
        }
    }

    static bool less(BigInt a, BigInt b)
    {
        if (equal(a,b))
        {
            return false;
        }
        else if (bigger(a,b))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    static bool equal(BigInt a, BigInt b)
    {
        if (a.mDigits.size() == b.mDigits.size() && a.mIsNegative == b.mIsNegative)
        {
            auto ita = a.mDigits.begin();
            auto itb = b.mDigits.begin();
            while (ita != a.mDigits.end())
            {
                if (*ita == *itb)
                {
                    ita++;
                    itb++;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    static bool equalBigger(BigInt a, BigInt b)
    {
        if (equal(a,b))
        {
            return true;
        }
        else if (bigger(a,b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static bool equalLess(BigInt a, BigInt b)
    {
        if (equal(a,b))
        {
            return true;
        }
        else if (less(a,b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static bool notEqual(BigInt a, BigInt b)
    {
        if (equal(a,b))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    static BigInt addValue(BigInt &a, BigInt &b)
    {
        BigInt r;
        r.mDigits.clear();

        if (a.mIsNegative && !b.mIsNegative)
        {
            a.mIsNegative = false;
            return sub(b,a);
        }

        if (!a.mIsNegative && b.mIsNegative)
        {
            b.mIsNegative = false;
            return sub(a,b);
        }

        reverse(a.mDigits.begin(), a.mDigits.end());
        reverse(b.mDigits.begin(), b.mDigits.end());

        auto it1 = a.mDigits.begin();
        auto it2 = b.mDigits.begin();
        int carry = 0;
        while (it1 != a.mDigits.end() || it2 != b.mDigits.end() || carry != 0)
        {
            int sum = carry;
            if (it1 != a.mDigits.end())
            {
                sum += *it1;
                it1++;
            }

            if (it2 != b.mDigits.end())
            {
                sum += *it2;
                it2++;
            }

            r.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(r.mDigits.begin(), r.mDigits.end());
        return r;
    }

    static BigInt sub(BigInt &a, BigInt &b)
    {
        BigInt r;
        r.mDigits.clear();


        if (a.mIsNegative && !b.mIsNegative)
        {
            a.mIsNegative = false;
            r = (addValue(a,b));
            r.mIsNegative = true;
            return r;
        }

        if (b.mIsNegative && !a.mIsNegative)
        {
            r.mIsNegative = false;
            b.mIsNegative = false;
            return addValue(a,b);
        }

        if (equal(a,b))
        {
            r.mDigits.push_back(0);
            return r;
        }

        if (a.mIsNegative && b.mIsNegative)
        {
            a.mIsNegative = false;
            b.mIsNegative = false;
            r.mIsNegative = true;
        }

        if (less(a,b))
        {
            r.mIsNegative = true;
            std::swap(a, b);
        }

        reverse(a.mDigits.begin(), a.mDigits.end());
        reverse(b.mDigits.begin(), b.mDigits.end());

        auto it1 = a.mDigits.begin(); //107
        auto it2 = b.mDigits.begin(); //48
        int carry = 0;
        while (it1 != a.mDigits.end() || it2 != b.mDigits.end())
        {
            int sum = carry; //
            carry = 0;
            if (it1 != a.mDigits.end())
            {
                sum += *it1; // 7
                if (*it1 == 0)
                {
                    sum += 10; // 9
                    carry--;   // -1
                }
                it1++;
            }

            if (it2 != b.mDigits.end())
            {
                sum -= *it2; // 7 - 8
                if (sum < 0)
                {
                    sum += *it2;
                    sum = (sum + 10) - *it2;
                    carry--;
                }
                sum = abs(sum);
                it2++;
            }
            r.mDigits.push_back(sum % 10); //  5
        }
        if (r.mDigits[r.mDigits.size() - 1] == 0)
        {
            r.mDigits.pop_back();
        }
        reverse(r.mDigits.begin(), r.mDigits.end());
        return r;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mDigits.empty()){
        out << 0;
    }
    if (x.mIsNegative)
    {
        out << '-';
    }

    int cnt = 0;

    for (auto digit : x.mDigits)
    {
        if (digit != 0){
            cnt++;
        }
        if (cnt != 0){
            out << digit;
        }
        
    }
    if (cnt == 0){
        out << 0;
    }
    return out;
}

inline bool operator==(BigInt a, BigInt b)
{
    return BigInt::equal(a, b);
}

inline bool operator>(BigInt a, BigInt b)
{
    return BigInt::bigger(a, b);
}

inline bool operator<(BigInt a, BigInt b)
{
    return BigInt::less(a, b);
}

inline bool operator>=(BigInt a, BigInt b)
{
    return BigInt::equalBigger(a, b);
}

inline bool operator<=(BigInt a, BigInt b)
{
    return BigInt::equalLess(a, b);
}

inline bool operator!=(BigInt a, BigInt b)
{
    return BigInt::notEqual(a, b);
}

inline BigInt operator+(BigInt a, BigInt b)
{
    return BigInt::addValue(a, b);
}

inline BigInt operator-(BigInt a, BigInt b)
{
    return BigInt::sub(a, b);
}