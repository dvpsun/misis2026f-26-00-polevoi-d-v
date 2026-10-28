#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[rationa] - ctor default") {
  Rational r0;
  CHECK(0 == r0.num());
  CHECK(1 == r0.den());
}

TEST_CASE("[rationa] - ctor") {
  Rational r1(3);
  CHECK(3 == r1.num());
  CHECK(1 == r1.den());
  Rational r2(-6, 2);
  CHECK(-3 == r2.num());
  CHECK(1 == r2.den());
  Rational r3(2, -6);
  CHECK(-1 == r2.num());
  CHECK(3 == r2.den());

  CHECK_THROWS(Rational(1, 0));
}
