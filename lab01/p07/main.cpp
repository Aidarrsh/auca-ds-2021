#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "Rational.hpp"

#include <sstream>
#include <cstdint>
using namespace std;

TEST_CASE("Rational: default constructor")
{

    Rational<int> r;

    vector<int> v(1000);

    ostringstream sout;
    sout << r;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Rational:constructor with numerator and denominator")
{

    ostringstream sout;

    SUBCASE("Test with 1/2")
    {
        Rational<int> r(1, 2);
        sout << r;
        REQUIRE(sout.str() == "1/2");
    }

    SUBCASE("Test with 3/2")
    {
        Rational<int> r(3, 2);
        sout << r;
        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("Test with 30/25")
    {
        Rational<int> r(30, 25);
        sout << r;
        REQUIRE(sout.str() == "6/5");
    }

    SUBCASE("Test with 17/31")
    {
        Rational<int> r(17, 31);
        sout << r;
        REQUIRE(sout.str() == "17/31");
    }

    SUBCASE("Test with -30/-20")
    {
        Rational<int> r(-30, -20);
        sout << r;
        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("Test with 30/-20")
    {
        Rational<int> r(30, -20);
        sout << r;
        REQUIRE(sout.str() == "-3/2");
    }

    SUBCASE("Test with 3/0")
    {
        REQUIRE_THROWS_AS(Rational<int>(3, 0), runtime_error);
    }
}

TEST_CASE("Rational: addition")
{
    ostringstream sout;

    SUBCASE("1/2+ 2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 + r2;

        REQUIRE(sout.str() == "5/6");
    }
}

TEST_CASE("Rational: substruction")
{
    ostringstream sout;

    SUBCASE("1/2 - 2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 - r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: multipliction")
{
    ostringstream sout;

    SUBCASE("1/2 * 2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 * r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: division")
{
    ostringstream sout;

    SUBCASE("1/2 :  2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 / r2;

        REQUIRE(sout.str() == "3/2");
    }
    SUBCASE("1/2 * 0/1")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(0, 1);

        REQUIRE_THROWS_AS(r1 / r2, runtime_error);
    }
}
TEST_CASE("Rational: less")
{
    ostringstream sout;

    SUBCASE("1/2 < 2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(2, 3);
        REQUIRE(r1 < r2);
    }
}
TEST_CASE("Rational: greater")
{
    ostringstream sout;

    SUBCASE("2/3 > 1/3")
    {
        Rational<int> r1(2, 3);
        Rational<int> r2(1, 2);
        REQUIRE(r1 > r2);
    }
}

TEST_CASE("Rational: not equal")
{
    ostringstream sout;

    SUBCASE("2/3 != 1/3")
    {
        Rational<int> r1(2, 3);
        Rational<int> r2(1, 2);
        REQUIRE(r1 != r2);
    }
}

TEST_CASE("Rational: greater or equal ")
{
    ostringstream sout;

    SUBCASE("2/3 >= 1/3")
    {
        Rational<int> r1(2, 3);
        Rational<int> r2(1, 2);
        REQUIRE(r1 >= r2);
    }
}

TEST_CASE("Rational: less or equal")
{
    ostringstream sout;

    SUBCASE("1/2 <= 1/2")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 2);
        REQUIRE(r1 <= r2);
    }
}
TEST_CASE("Rational: equal")
{
    ostringstream sout;

    SUBCASE("1/2 == 1/2")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 2);
        REQUIRE(r1 == r2);
    }
}
TEST_CASE("Rational: getters")
{
    const Rational<int64_t> r;

    REQUIRE(r.num() == 0);
    REQUIRE(r.den() == 1);
}

TEST_CASE("Rational: input operator")
{
    SUBCASE("1/2")
    {
        istringstream sinp("1/2 42");

        Rational<int> r;
        int x;
        sinp >> r >> x;

        ostringstream sout;
        sout << r;
        REQUIRE(sout.str() == "1/2");
        REQUIRE(x == 42);
    }

    SUBCASE("-1/2")
    {
        istringstream sinp("-1/2");

        Rational<int> r;

        sinp >> r;

        ostringstream sout;
        sout << r;
        REQUIRE(sout.str() == "-1/2");
    }
    SUBCASE("one over two")
    {
        istringstream sinp("one over two");
        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
   SUBCASE("1:-2")
    {
        istringstream sinp("1:-2");

        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
}