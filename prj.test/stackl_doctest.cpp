// 2024 by Polevoi Dmitry under Unlicense

#include <stackl/stackl.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stackl] - ctor") {
  CHECK(StackL().is_empty());
}
