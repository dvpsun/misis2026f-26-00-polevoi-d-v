// 2026 by Polevoy Dmitry
// task description https://codeforces.com/problemset/problem/271/A
// 271A Красивый год

#if defined WITH_DOCTEST
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#endif

#include <iostream>

int calc_beaty_year(const int year) {
  // проверка на красивость со следующего
  int y = year + 1;
  for (; y < 9999; y += 1) {
    // выделим разряды
    const int d1 = y / 1000;
    const int d2 = y / 100 % 10;
    const int d3 = y / 10 % 10;
    const int d4 = y % 10;
    // проверим на красоту
    bool is_beaty = d4 != d3;
    is_beaty = is_beaty && d4 != d2;
    is_beaty = is_beaty && d4 != d1;
    is_beaty = is_beaty && d3 != d2;
    is_beaty = is_beaty && d3 != d1;
    is_beaty = is_beaty && d2 != d1;
    if (is_beaty) {
      // для красивого года конец работы цикла
      break;
    }
  }
  return y;
}

#if defined WITH_DOCTEST
TEST_CASE("271a") {
  CHECK_EQ(calc_beaty_year(1000), 1023);
  CHECK_EQ(calc_beaty_year(3245), 3246);
}
#endif

int main(int argc, char** argv) {
#if defined WITH_DOCTEST
  if (1 < argc) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    //context.setOption("no-breaks", true);
    return context.run();
  }
#endif

  int year = 0;
  std::cin >> year;
  std::cout << calc_beaty_year(year);
}
