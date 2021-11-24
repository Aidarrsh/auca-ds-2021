#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <sstream>

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
        BigInt a(-23082202);

        sout << a;

        REQUIRE(sout.str() = "-23082002");
    }
}