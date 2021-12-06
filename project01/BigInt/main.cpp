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

    // SUBCASE("-5 + 5")
    // {
    //     BigInt x(-5);
    //     BigInt y(5);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "0");
    // }
}

TEST_CASE("Substraction")
{
    ostringstream sout;

    SUBCASE("12-7")
    {
        BigInt x(12);
        BigInt y(7);

        sout << x - y;

        REQUIRE(sout.str() == "5");
    }

    SUBCASE("45-47")
    {
        BigInt x(45);
        BigInt y(47);

        sout << x - y;

        REQUIRE(sout.str() == "-2");
    }

    SUBCASE("82-100")
    {
        BigInt x(82);
        BigInt y(100);

        sout << x - y;

        REQUIRE(sout.str() == "-18");
    }

    SUBCASE("100-82")
    {
        BigInt x(100);
        BigInt y(82);

        sout << x - y;

        REQUIRE(sout.str() == "18");
    }
    SUBCASE("5-5")
    {
        BigInt x(5);
        BigInt y(5);

        sout << x - y;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("5-(-5)")
    {
        BigInt x(5);
        BigInt y(-5);

        sout << x - y;

        REQUIRE(sout.str() == "10");
    }

    SUBCASE("-5 - 5")
    {
        BigInt x(-5);
        BigInt y(5);

        sout << x - y;

        REQUIRE(sout.str() == "-10");
    }

    SUBCASE("-200 - (-5)")  // 5-200     
    {
        BigInt x(-200);
        BigInt y(-5);

        sout << x - y;

        REQUIRE(sout.str() == "-195");
    }

    SUBCASE("5 - 200")  // 5-200     
    {
        BigInt x(5);
        BigInt y(200);

        sout << x - y;

        REQUIRE(sout.str() == "-195");
    }
}

TEST_CASE("COMPARE")
{
    ostringstream sout;
    
    SUBCASE("2021 == 2021")
    {
        BigInt x("2021");
        BigInt y(2021);

        REQUIRE(x == y);
    }

    SUBCASE("2021 > 2002")
    {
        BigInt x("2021");
        BigInt y(2002);

        REQUIRE(x > y);
    }

    SUBCASE("2021 < 2077")
    {
        BigInt x("2021");
        BigInt y(2077);

        REQUIRE(x < y);
    }

    SUBCASE("2021 >= 2020")
    {
        BigInt x("2021");
        BigInt y(2020);

        REQUIRE(x >= y);
    }

    SUBCASE("2021 >= 2021")
    {
        BigInt x("2021");
        BigInt y(2021);

        REQUIRE(x >= y);
    }

    SUBCASE("2021 <= 2021")
    {
        BigInt x("2021");
        BigInt y(2021);

        REQUIRE(x <= y);
    }

    SUBCASE("2077 >= 2021")
    {
        BigInt x("2077");
        BigInt y(2021);

        REQUIRE(x >= y);
    }

    SUBCASE("2021 != 2077")
    {
        BigInt x("2021");
        BigInt y(2077);

        REQUIRE(x != y);
    }
}