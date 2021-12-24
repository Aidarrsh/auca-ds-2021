#ifndef VECINT_HPP
#define VECINT_HPP

#include <cstddef>
#include <iostream>
#include <initializer_list>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt
{
    int *data;
    size_t sz;
    size_t cp;

public:
    static size_t numOfCopies;

    using Iter = int *;
    using CIter = const int *;

    VecInt()
        : data(nullptr), sz(0), cp(0)
    {
    }

    explicit VecInt(size_t size, int initValue = 0)
        : data(new int[size]), sz(size), cp(size)
    {
        for (size_t i = 0; i < size; i++)
            data[i] = initValue;
    }

    VecInt(std::initializer_list<int> initList)
        : VecInt()
    {
        for (auto e : initList)
        {
            push_back(e);
        }
    }

    // copy constructor
    VecInt(const VecInt &other);

    // assignment operator
    VecInt &operator=(const VecInt &other);

    // move constructor
    VecInt(VecInt &&other);

    // move assigment operator
    VecInt &operator=(VecInt &&other) noexcept;

    ~VecInt()
    {
        std::cout << "~VecInt: " << sz << " integers released\n";
        delete[] data;
    }

    size_t size() const
    {
        return sz;
    }

    Iter begin()
    {
        return data;
    }

    Iter end()
    {
        return data + sz;
    }

    CIter begin() const
    {
        return data;
    }

    CIter end() const
    {
        return data + sz;
    }

    const int &operator[](std::size_t index) const
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            trow std::runtime_error("VecInt: incorrect index: " + std::to_string(index))
        }
#endif
        return data[index];
    }

    int &operator[](std::size_t index)
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            trow std::runtime_error("VecInt: incorrect index: " + std::to_string(index))
        }
#endif
        return data[index];
    }

    void push_back(int x);
};

#endif

bool operator==(const VecInt &a, const VecInt &b);

bool operator!=(const VecInt &a, const VecInt &b);