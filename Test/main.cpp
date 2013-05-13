#define BOOST_TEST_MODULE WindowTest
#include "Vector2d.h"
#include "Rectangle.h"
#include <boost\test\included\unit_test.hpp>

#include <iostream>
#include <memory>

typedef UsefulMath::Vector2 Vec2;

BOOST_AUTO_TEST_CASE( VecConstructor )
{
	Vec2 v(1.f, 2.f);
    BOOST_REQUIRE( v.x == 1.f && v.y == 2.f );
}

BOOST_AUTO_TEST_CASE( RecConstructor )
{
	UsefulMath::Rectangle r(Vec2(1.f, 2.f),Vec2(1.f, 2.f));
    BOOST_REQUIRE( r.left == 1.f && r.bottom == 4.f );
}



BOOST_AUTO_TEST_CASE( TestingDone )
{
	std::cout << "Testing done!" << std::endl;
	std::cin.get();
}