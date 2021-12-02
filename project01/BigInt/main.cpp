#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("Default constructor")
{
    BigInt a;
    ostringstream sout;
    sout << a;

    REQUIRE(sout.str() == "0");
}

TEST_CASE("Integer constructor")
{
    ostringstream sout;

    SUBCASE("Test with 228")
    {
        BigInt a(228);

        sout << a;

        REQUIRE(sout.str() == "228");
    }

    SUBCASE("Test with -23082002")
    {
        BigInt a(-23082002);

        sout << a;

        REQUIRE(sout.str() == "-23082002");
    }
}

TEST_CASE("String constructor")
{
    ostringstream sout;

    SUBCASE("Test with 228")
    {
        BigInt a("228");
        
        sout << a;

        REQUIRE(sout.str() == "228");
    }

    SUBCASE("Test with -23082002")
    {
        BigInt a("-23082002");

        sout << a;

        REQUIRE(sout.str() == "-23082002");
    }

    SUBCASE("Wrong input")
    {
        REQUIRE_THROWS_AS(BigInt a("Aidar");, runtime_error);
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;

    SUBCASE("123 + 19")
    {
        BigInt x(123);
        BigInt y(19);

        sout << x + y;

        REQUIRE(sout.str() == "142");
    }

    SUBCASE("123456789 + 228")
    {
        BigInt x(123456789);
        BigInt y(228);

        sout << x + y;

        REQUIRE(sout.str() == "123457017");
    }
}

TEST_CASE("COMPARE")
{
    ostringstream sout;
    
    SUBCASE("2021 == 2021")
    {
        BigInt x("2021");
        BigInt y("2021");

        REQUIRE(x == y);
    }
}