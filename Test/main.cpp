#define BOOST_TEST_MODULE WindowTest
#include "Vector2d.h"
#include <boost\test\included\unit_test.hpp>

#include <iostream>
#include <memory>

typedef UsefulMath::Vector2 Vec2;

BOOST_AUTO_TEST_CASE( Constructor )
{
	Vec2 v(1.f, 2.f);
    BOOST_REQUIRE( v.x == 1.f && v.y == 2.f );

	std::cin.get();
}