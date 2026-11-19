// 2024 by Polevoi Dmitry under Unlicense

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <queuea/queuea.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <array>

using QueueA_T = uint8_t;

TEST_CASE("[queuea] - ctor") {
  QueueA st;
}

TEST_CASE("[queuea] - isempty") {
  QueueA st;
  CHECK(st.is_empty());
  st.push(QueueA_T());
  CHECK(!st.is_empty());
}

//TEST_CASE("[queuea] - clear") {
//  QueueA st_orig;
//  st_orig.push(QueueA_T());
//  CHECK(!st_orig.is_empty());
//  st_orig.clear();
//  CHECK(st_orig.is_empty());
//  QueueA st_src;
//  for (int i = 0; i < 10; i += 1) {
//    st_src.push(QueueA_T(i * 1.0));
//  }
//  CHECK(!st_src.is_empty());
//  st_orig = st_src;
//}

TEST_CASE("[queue cmd] - copy ctor") {
  QueueA st_orig;
  QueueA st_empty(st_orig);
  CHECK(st_empty.is_empty());

  {
    st_orig.push(QueueA_T(1));
    st_orig.push(QueueA_T(2));
    st_orig.pop();
    st_orig.push(QueueA_T(3));
    QueueA st_copy(st_orig);
    CHECK(!st_copy.is_empty());
    //CHECK_NE(&st_orig.top(), &st_copy.top());
    CHECK_EQ(st_orig.top(), st_copy.top());
    st_copy.pop();
    //CHECK_NE(&st_orig.top(), &st_copy.top());
    CHECK_NE(st_orig.top(), st_copy.top());
    while (!st_orig.is_empty()) {
      st_orig.pop();
      if (!st_orig.is_empty()) {
        CHECK_EQ(st_orig.top(), st_copy.top());
      }
      st_copy.pop();
      if (!st_copy.is_empty()) {
        CHECK_NE(st_orig.top(), st_copy.top());
      }
    }
  }

  for (double v = 0.0; v < 100.1; v += 1.0) {
    st_orig.push(QueueA_T(v));
  }
  CHECK(!st_orig.is_empty());
  QueueA st_copy(st_orig);
  CHECK(!st_copy.is_empty());
  //CHECK_NE(&st_orig.top(), &st_copy.top());
  CHECK_EQ(st_orig.top(), st_copy.top());
  st_copy.pop();
  CHECK_NE(st_orig.top(), st_copy.top());
  CHECK_NE(st_orig.top(), st_copy.top());
  while (!st_orig.is_empty()) {
    st_orig.pop();
    if (!st_orig.is_empty()) {
      CHECK_EQ(st_orig.top(), st_copy.top());
    }
    st_copy.pop();
    if (!st_copy.is_empty()) {
      CHECK_NE(st_orig.top(), st_copy.top());
    }
  }
}

TEST_CASE("[queuea] - operator=") {
  QueueA st_orig;
  QueueA st_empty;
  st_empty = st_orig;
  CHECK(st_empty.is_empty());
  for (double v = 0.0; v < 4.1; v += 1.0) {
    st_orig.push(QueueA_T(v));
  }
  CHECK(!st_orig.is_empty());
  st_orig = st_empty;
  CHECK(st_orig.is_empty());
  for (double v = 0.0; v < 4.1; v += 1.0) {
    st_orig.push(QueueA_T(v));
  }
  st_empty.push({});
  st_empty.push({});
  st_orig = st_empty;
  CHECK(!st_orig.is_empty());
  st_orig.pop();
  st_orig.pop();
  CHECK(st_orig.is_empty());


  for (double v = 0.0; v < 100.1; v += 1.0) {
    st_orig.push(QueueA_T(v));
  }
  QueueA st_copy;
  st_copy = st_orig;
  //CHECK_NE(&st_orig.top(), &st_copy.top());
  while (!st_orig.is_empty()) {
    CHECK_EQ(st_orig.top(), st_copy.top());
    st_orig.pop();
    if (!st_orig.is_empty()) {
      CHECK_NE(st_orig.top(), st_copy.top());
    }
    st_copy.pop();
    if (!st_copy.is_empty()) {
      CHECK_EQ(st_orig.top(), st_copy.top());
    }
  }
}

TEST_CASE("[queuea] - top") {
  QueueA st_orig;
  CHECK_THROWS(void(st_orig.top()));
  const QueueA& st_refc = st_orig;
  CHECK_THROWS(void(st_refc.top()));
  st_orig.push({});
  CHECK_NOTHROW(void(st_orig.top()));
  CHECK_NOTHROW(void(st_refc.top()));
  st_orig.pop();
  CHECK_NOTHROW(void(st_orig.pop()));
  QueueA st_copy(st_orig);
  CHECK(st_orig.is_empty());
  st_orig.push({});
  CHECK(st_copy.is_empty());
  CHECK(!st_orig.is_empty());
}