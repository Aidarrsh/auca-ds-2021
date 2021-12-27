#include <bits/stdc++.h>

using namespace std;
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }


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
        //    mDigits.push_back(0);
    }

    BigInt(int n) : BigInt(std::to_string(n))
    {
        // if (n < 0)
        // {
        //     mIsNegative = true;
        //     n = -n;
        // }
        // else
        // {
        //     mIsNegative = false;
        // }

        // while (n)
        // {
        //     int temp = n % 10;
        //     mDigits.push_back(temp);
        //     n /= 10;
        // }

        // reverse(mDigits.begin(), mDigits.end());
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
        if (equal(a, b))
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
                        while (it1 != a.mDigits.end()) //// 2225   2334
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
        if (equal(a, b))
        {
            return false;
        }
        else if (bigger(a, b))
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
            auto it1 = a.mDigits.begin();
            auto it2 = b.mDigits.begin();
            while (it1 != a.mDigits.end())
            {
                if (*it1 == *it2)
                {
                    it1++;
                    it2++;
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
        if (equal(a, b))
        {
            return true;
        }
        else if (bigger(a, b))
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
        if (equal(a, b))
        {
            return true;
        }
        else if (less(a, b))
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
        if (equal(a, b))
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
            return sub(b, a);
        }

        if (!a.mIsNegative && b.mIsNegative)
        {
            b.mIsNegative = false;
            return sub(a, b);
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
            r = (addValue(a, b));
            r.mIsNegative = true;
            return r;
        }

        if (b.mIsNegative && !a.mIsNegative)
        {
            r.mIsNegative = false;
            b.mIsNegative = false;
            return addValue(a, b);
        }

        if (equal(a, b))
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

        if (less(a, b))
        {
            r.mIsNegative = true;
            std::swap(a, b);
        }

        reverse(a.mDigits.begin(), a.mDigits.end());
        reverse(b.mDigits.begin(), b.mDigits.end());

        auto it1 = a.mDigits.begin(); //106
        auto it2 = b.mDigits.begin(); //3
        int carry = 0;
        while (it1 != a.mDigits.end() || it2 != b.mDigits.end())
        {
            int sum = carry; //
            carry = 0;
            if (it1 != a.mDigits.end())
            {
                sum += *it1; // 0
                if (*it1 == 0)
                {
                    sum += 10; //
                    carry--;   //
                }
                it1++;
            }

            if (it2 != b.mDigits.end())
            {
                sum -= *it2; // 6 - 3
                if (sum < 0)
                {
                    sum += *it2;
                    sum = (sum + 10) - *it2;
                    carry--;
                }
                if (*it2 == 0 && sum == 10)
                {
                    carry++;
                }
                sum = abs(sum);
                it2++;
            }
            else
            {
                if (sum == 10)
                {
                    carry++;
                }
            }
            r.mDigits.push_back(sum % 10); //  5
        }
        reverse(r.mDigits.begin(), r.mDigits.end());
        return r;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mDigits.empty())
    {
        out << 0;
        return out;
    }
    if (x.mIsNegative)
    {
        out << '-';
    }

    int cnt = 0;

    for (auto digit : x.mDigits)
    {
        if (digit != 0)
        {
            cnt++;
        }
        if (cnt != 0)
        {
            out << digit;
        }
    }
    if (cnt == 0)
    {
        out << 0;
    }
    return out;
}

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    std::string s;

    if (!(inp >> s))
    {
        return inp;
    }

    x = BigInt(s);

    return inp;
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

inline BigInt operator*(BigInt a, BigInt b)
{
    BigInt r;
    r.mDigits.clear();
    if (a.mIsNegative != b.mIsNegative)
    {
        r.mIsNegative = true;
    }

    // if (a == 0 || b == 0)
    // {
    //     return 0;
    // }

    auto it2 = b.mDigits.rbegin();
    a.mIsNegative = false, b.mIsNegative = false;
    int shift = 0;
    while (it2 != b.mDigits.rend())
    {
        auto it1 = a.mDigits.rbegin();
        int carry = 0;
        int currShift = shift;
        while (it1 != a.mDigits.rend() || carry != 0)
        {
            int sum = carry;
            if (it1 != a.mDigits.rend())
            {
                sum = *it1 * (*it2) + sum;
                it1++;
            }
            if (currShift < (int)r.mDigits.size())
            {
                carry = (r.mDigits[currShift] + sum) / 10;
                r.mDigits[currShift] = (r.mDigits[currShift] + sum) % 10;
            }
            else
            {
                r.mDigits.push_back(sum % 10);
                carry = sum / 10;
            }
            currShift++;
        }
        shift++;
        it2++;
    }
    reverse(r.mDigits.begin(), r.mDigits.end());
    return r;
}

inline BigInt operator/(BigInt a, BigInt b)
{
    BigInt r;

    r.mDigits.clear();

    if (a == BigInt())
    {
        return 0;
    }

    if (b == BigInt())
    {
        throw std::runtime_error("Divisor can't be zero");
    }

    if ((a.mIsNegative && !b.mIsNegative))
    {
        r.mIsNegative = true;
        a.mIsNegative = false;
        if (a < b)
        {
            return 0;
        }
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        r.mIsNegative = true;
        b.mIsNegative = false;
    }

    if (a.mIsNegative && b.mIsNegative)
    {
        r.mIsNegative = false;
        a.mIsNegative = false;
        b.mIsNegative = false;
    }

    auto it1 = a.mDigits.begin();

    BigInt temp;
    temp.mDigits.clear();
    int res = 0;

    // if (a.mDigits.size() > b.mDigits.size())
    // {
    //     temp.mDigits.push_back(*it1);
    //     it1++;
    // }

    BigInt zero;
    zero.mDigits.push_back(0);

    while (it1 != a.mDigits.end()) // 1204 / 2
    {
        if (temp == zero)
        {
            temp.mDigits.clear();
        }
        temp.mDigits.push_back(*it1);

        if (temp == 0)
        {
            res = 0;
        }

        while (temp >= b)
        {
            std::stringstream ss;
            ss << temp - b;
            temp = BigInt(ss.str());
            res++;
        }

        r.mDigits.push_back(res);
        res = 0;
        it1++;
    }

    return r;
}

inline BigInt operator%(BigInt a, BigInt b)
{
    BigInt r;
    bool minus = false;

    r.mDigits.clear();

    if (a.mIsNegative)
    {
        minus = true;
        a.mIsNegative = false;
        if (a < b)
        {
            return 0;
        }
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        minus = false;
        b.mIsNegative = false;
    }

    if (a.mIsNegative && b.mIsNegative)
    {
        minus = true;
        a.mIsNegative = false;
        b.mIsNegative = false;
    }

    BigInt zero;

    zero.mDigits.push_back(0);

    auto it1 = a.mDigits.begin();
    while (it1 != a.mDigits.end()) // 1204 / 2
    {
        if (r == zero)
        {
            r.mDigits.clear();
        }
        r.mDigits.push_back(*it1);

        while (r >= b)
        {
            std::stringstream ss;
            ss << r - b; // 1001 % 10
            r = BigInt(ss.str());
        }
        it1++;
    }
    r.mIsNegative = minus;
    return r;
}

inline BigInt abs(BigInt r)
{
    r.mIsNegative = false;
    return r;
}

inline BigInt operator++(BigInt &r)
{
    r = r + (BigInt)1;

    return r;
}

inline BigInt operator++(BigInt &r, int)
{
    BigInt temp;
    ++r;
    return temp;
}

inline BigInt operator--(BigInt &r)
{
    r = r - (BigInt)1;

    return r;
}

inline BigInt operator--(BigInt &r, int)
{
    BigInt temp;
    --r;
    return temp;
}

inline BigInt operator+=(BigInt &a, BigInt &b)
{
    a = a + b;
    return a;
}

inline BigInt operator-=(BigInt &a, BigInt &b)
{
    a = a - b;
    return a;
}

inline BigInt operator*=(BigInt &a, BigInt &b)
{
    a = a * b;
    return a;
}

inline BigInt operator/=(BigInt &a, BigInt &b)
{
    a = a / b;
    return a;
}

inline BigInt operator%=(BigInt &a, BigInt &b)
{
    a = a % b;
    return a;
}

int main()
{
    iostream::sync_with_stdio(false);
    int n , a;
    while(cin >> a >> n)
    {
        BigInt x (n);
        BigInt res (0);
        for (int i = 1; i <= a; i++)
        {
            BigInt temp(i);
            BigInt temp1(n);
            for (int j = 1; j < i; j++)
            {
                temp1 *= x;
            }
            res = res + (temp * temp1);
        }
        cout << res << endl;
    }
}