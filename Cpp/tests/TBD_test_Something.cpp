#include "doctest.h"
#include "fakeit.hpp"

using fakeit::Mock;
using fakeit::When;

TEST_SUITE_BEGIN("unit");

TEST_CASE("A passing test"){
	CHECK(true);
}

TEST_SUITE_END();
