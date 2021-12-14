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

    SUBCASE("-5 + 5")
    {
        BigInt x(-5);
        BigInt y(5);

        sout << x + y;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("-228 + 5")
    {
        BigInt x(-228);
        BigInt y(5);

        sout << x + y;

        REQUIRE(sout.str() == "-223");
    }

    SUBCASE("5 + (-5)")
    {
        BigInt x(5);
        BigInt y(-5);

        sout << x + y;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("5 + (-228)")
    {
        BigInt x(5);
        BigInt y(-228);

        sout << x + y;

        REQUIRE(sout.str() == "-223");
    }
}

TEST_CASE("Substraction")
{
    ostringstream sout;

    SUBCASE("0-1")
    {
        BigInt x(0);
        BigInt y(1);

        sout << x - y;

        REQUIRE(sout.str() == "-1");
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

    SUBCASE("-200 - (-5)") // 5-200
    {
        BigInt x(-200);
        BigInt y(-5);

        sout << x - y;

        REQUIRE(sout.str() == "-195");
    }

    SUBCASE("5 - 200") // 5-200
    {
        BigInt x(5);
        BigInt y(200);

        sout << x - y;

        REQUIRE(sout.str() == "-195");
    }

    // SUBCASE("super test")
    // {
    //     for (int i = 100; i <= 110; i++) {
    //         BigInt a (i);
    //         for (int j = -100; j <= 100; j++) {
    //             int sum = i - j;
    //             cout << i << "-" << j << "\n";//use to see which test it fails
    //             stringstream ss;
    //             BigInt b (j);
    //             ss << a - b;
    //             CHECK(ss.str() == to_string(sum));
    //         }
    //     }
    // }

    SUBCASE("100 - 47")
    {
        BigInt x("100");
        BigInt y("47");

        sout << x - y;

        REQUIRE(sout.str() == "53");
    }

    SUBCASE("0 - 7")
    {
        BigInt x("0");
        BigInt y("7");

        sout << x - y;

        REQUIRE(sout.str() == "-7");
    }
}

TEST_CASE("MULTIPLICATION")
{
    ostringstream sout;

    SUBCASE("25 * 5")
    {
        BigInt x("25");
        BigInt y("5");

        sout << x * y;

        REQUIRE(sout.str() == "125");
    }

    SUBCASE("25 * 25")
    {
        BigInt x("25");
        BigInt y("25");

        sout << x * y;

        REQUIRE(sout.str() == "625");
    }

    SUBCASE("15 * 5")
    {
        BigInt x("15");
        BigInt y("5");

        sout << x * y;

        REQUIRE(sout.str() == "75");
    }

    SUBCASE("5 * 15")
    {
        BigInt x("5");
        BigInt y("15");

        sout << x * y;

        REQUIRE(sout.str() == "75");
    }

    SUBCASE("0 * 100")
    {
        BigInt x("0");
        BigInt y("100");

        sout << x * y;

        REQUIRE(sout.str() == "0");
    }

    // SUBCASE("Super Test")
    // {
    //     for (int i = -50; i <= 50; i++)
    //     {
    //         BigInt a(i);
    //         for (int j = 1; j <= 50 && j != 0; j++)
    //         {
    //             int sum = i * j;
    //             cout << i << "*" << j << "\n"; 
    //             stringstream ss;
    //             BigInt b(j);
    //             ss << a * b;
    //             CHECK(ss.str() == to_string(sum));
    //         }
    //     }
    // }
}

TEST_CASE("DIVISION")
{
    ostringstream sout;

    SUBCASE("9 / 3")
    {
        BigInt x("9");
        BigInt y("3");

        sout << x / y;

        REQUIRE(sout.str() == "3");
    }

    SUBCASE("125 / 5")
    {
        BigInt x("125");
        BigInt y("5");

        sout << x / y;

        REQUIRE(sout.str() == "25");
    }

    SUBCASE("63 / 7")
    {
        BigInt x("63");
        BigInt y("7");

        sout << x / y;

        REQUIRE(sout.str() == "9");
    }

    SUBCASE("1010 / 10")
    {
        BigInt x("1010");
        BigInt y("10");

        sout << x / y;

        REQUIRE(sout.str() == "101");
    }

    SUBCASE("1204 / 2")
    {
        BigInt x("1204");
        BigInt y("2");

        sout << x / y;

        REQUIRE(sout.str() == "602");
    }

    SUBCASE("-1204 / 2")
    {
        BigInt x("-1204");
        BigInt y("2");

        sout << x / y;

        REQUIRE(sout.str() == "-602");
    }

    SUBCASE("1204 / -2")
    {
        BigInt x("1204");
        BigInt y("-2");

        sout << x / y;

        REQUIRE(sout.str() == "-602");
    }

    SUBCASE("-1204 / -2")
    {
        BigInt x("-1204");
        BigInt y("-2");

        sout << x / y;

        REQUIRE(sout.str() == "602");
    }

    SUBCASE("100 / 2")
    {
        BigInt x("100");
        BigInt y("2");

        sout << x / y;

        REQUIRE(sout.str() == "50");
    }

    // SUBCASE("Super Test")
    // {
    //     for (int i = 1000; i <= 1100; i++)
    //     {
    //         BigInt a(i);
    //         for (int j = -1000; j <= 1000 && j != 0; j++)
    //         {
    //             int sum = i / j;
    //             cout << i << "/" << j << "\n"; 
    //             stringstream ss;
    //             BigInt b(j);
    //             ss << a / b;
    //             CHECK(ss.str() == to_string(sum));
    //         }
    //     }
    // }
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

TEST_CASE("MOD")
{
    ostringstream sout;

    SUBCASE("5 % 2")
    {
        BigInt x("5");
        BigInt y("2");

        sout << x % y;

        REQUIRE(sout.str() == "1");
    }

    SUBCASE("239 % 16")
    {
        BigInt x("239");
        BigInt y("16");

        sout <<x % y;

        REQUIRE(sout.str() == "15");
    }

    SUBCASE("-239 % 16")
    {
        BigInt x("-239");
        BigInt y("16");

        sout <<x % y;

        REQUIRE(sout.str() == "-15");
    }

    SUBCASE("239 % (-16)")
    {
        BigInt x("239");
        BigInt y("-16");

        sout <<x % y;

        REQUIRE(sout.str() == "15");
    }

    SUBCASE("4638746747645731289347483927 % 6784789")
    {
        BigInt x("4638746747645731289347483927");
        BigInt y("6784789");

        sout <<x % y;

        REQUIRE(sout.str() == "1001783");
    }

    SUBCASE("1100 % 11")
    {
        BigInt x("1100");
        BigInt y("11");

        sout <<x % y;

        REQUIRE(sout.str() == "0");
    }

    // SUBCASE("Super Test")
    // {
    //     for (int i = 1000; i <= 1100; i++)
    //     {
    //         BigInt a(i);
    //         for (int j = -1000; j <= 1000 && j != 0; j++)
    //         {
    //             int sum = i % j;
    //             cout << i << "%" << j << "\n"; 
    //             stringstream ss;
    //             BigInt b(j);
    //             ss << a % b;
    //             CHECK(ss.str() == to_string(sum));
    //         }
    //     }
    // }
}

TEST_CASE("Unary and Binary")
{
    ostringstream sout;
    SUBCASE("++")
    {
        BigInt x("1");

        sout <<++x;

        REQUIRE(sout.str() == "2");
    }

    SUBCASE("++")
    {
        BigInt x("-2");

        x++;

        sout <<x;

        REQUIRE(sout.str() == "-1");
    }

    SUBCASE("--")
    {
        BigInt x("0");

        x--;

        sout <<x;

        REQUIRE(sout.str() == "-1");
    }

    SUBCASE("+=")
    {
        BigInt x("5");
        BigInt y("7");
        
        x+=y;

        sout <<x;

        REQUIRE(sout.str() == "12");
    }

    SUBCASE("-=")
    {
        BigInt x("5");
        BigInt y("7");
        
        x-=y;

        sout <<x;

        REQUIRE(sout.str() == "-2");
    }

    SUBCASE("*=")
    {
        BigInt x("5");
        BigInt y("7");
        
        x*=y;

        sout <<x;

        REQUIRE(sout.str() == "35");
    }

    SUBCASE("/=")
    {
        BigInt x("35");
        BigInt y("7");
        
        x/=y;

        sout <<x;

        REQUIRE(sout.str() == "5");
    }

    SUBCASE("%=")
    {
        BigInt x("36");
        BigInt y("7");
        
        x%=y;

        sout <<x;

        REQUIRE(sout.str() == "1");
    }
}

TEST_CASE("abs")
{
    ostringstream sout;

    BigInt x(-100);

    sout <<abs(x);

    REQUIRE(sout.str() == "100");
}