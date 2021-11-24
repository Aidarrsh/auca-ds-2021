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