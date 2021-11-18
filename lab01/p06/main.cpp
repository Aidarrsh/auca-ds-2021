#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
template <typename Container>
string containerToStr(const Container &c)
{
    ostringstream sinp;

    sinp << "{";

    bool isFirst = true;
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sinp << ", ";
        }
        sinp << e;
        isFirst = false;
    }

    sinp << "}";

    return sinp.str();
}

TEST_CASE("vector's default constructor")
{
    vector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("vector's constractor with count copies")
{
    vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v2(3);

    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0].empty());
    REQUIRE(v2[1].empty());
    REQUIRE(v2[2].empty());

    vector<int> v3(3, 42);

    REQUIRE(v3.size() == 3);
    REQUIRE(v3[0] == 42);
    REQUIRE(v3[1] == 42);
    REQUIRE(v3[2] == 42);
}

TEST_CASE("vector's copy constractor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = v;
    v[1] = 1000;

    REQUIRE(v2[1] != v[1]);
    REQUIRE(v[1] == 1000);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("vector's move constractor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = move(v);

    REQUIRE(v.empty());
    REQUIRE(v2.size() == 3);

    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("vector's assignment operator")
{
    vector<int> v = {1, 2, 3};

    vector<int> v2 = {10, 20};

    v2 = v;
    REQUIRE(v2.size() == 3);
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");

    v[1] = 1000;

    REQUIRE(containerToStr(v) == "{1, 1000, 3}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
}

TEST_CASE("vector's at operator")
{
    vector<int> v = {10, 2, 3};

    REQUIRE_THROWS_AS(v.at(3), out_of_range);
}

TEST_CASE("push_back method")
{
    vector<int> v;
    v.push_back(4);
    REQUIRE(v[0] == 4);
}

TEST_CASE("the work of for (auto element : container) statement with std::vector")
{
    vector<int> v = {3, 4, 5, 6, 7};
    vector<int> v1;
    for (auto e : v)
    {
        v1.push_back(e);
    }
    REQUIRE(v1.size() == 5);
}

TEST_CASE("the work of std::reverse algorithm with std::vector")
{
    vector<int> v = {3, 4, 5, 6, 7};
    reverse(v.begin(), v.end());
    REQUIRE(v[0] == 7);
}

TEST_CASE("the work of std::sort algorithm with std::vector")
{
    vector<int> v = {4, 5, 10, 8, 9};
    sort(v.begin(), v.end());
    REQUIRE(v[4] == 10);
}

TEST_CASE("the work of std::binary_search algorithm with std::vector")
{
    vector<int> v = {4, 5, 10, 8, 9};
    REQUIRE(binary_search(v.begin(), v.end(), 4));
}

TEST_CASE("the work of std::min_element algorithm with std::vector")
{
    vector<int> v = {4, 5, 10, 8, 9};
    REQUIRE(*min_element(v.begin(), v.end()) == 4);
}

TEST_CASE("the work of std::max_element algorithm with std::vector")
{
    vector<int> v = {4, 5, 10, 8, 9};
    REQUIRE(*max_element(v.begin(), v.end()) == 10);
}

TEST_CASE("type std::vector<T>::iterator: *, ++, --, it + n, it – n, it2 - it1")
{
    vector<int> v = {4, 5, 10, 8, 9};
    v[0] *= 3;
    v[0]++;
    v[1] += 5;
    v[2] -= 5;
    v[4] -= v[3];
    REQUIRE(v[0] == 13);
    REQUIRE(v[1] == 10);
    REQUIRE(v[2] == 5);
    REQUIRE(v[4] == 1);
}
