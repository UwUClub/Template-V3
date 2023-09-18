#include <catch2/catch_test_macros.hpp>
#include <factorial.hpp>

TEST_CASE("Factorials are computed", "[factorial]")
{
    factorial factorial;
    REQUIRE(factorial.factorial_function(-2) == -1);
    REQUIRE(factorial.factorial_function(0) == 1);
    REQUIRE(factorial.factorial_function(1) == 1);
    REQUIRE(factorial.factorial_function(2) == 2);
    REQUIRE(factorial.factorial_function(3) == 6);
    REQUIRE(factorial.factorial_function(10) == 3628800);
}
