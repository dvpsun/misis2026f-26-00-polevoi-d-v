// 2021 by Polevoy Dmitry
// task description https://codeforces.com/problemset/problem/271/A
// 271A Красивый год

#include <iostream>

int main() {
  int y = 0;
  std::cin >> y;
  // проерка на краисовость со следующего
  for (int b = y + 1; b < 9999; b += 1) {
    // выделим разряды
    const int d1 = b / 1000;
    const int d2 = b / 100 % 10;
    const int d3 = b / 10 % 10;
    const int d4 = b % 10;
    // проверим на красоту
    bool is_beaty = d4 != d3;
    is_beaty = is_beaty && d4 != d2;
    is_beaty = is_beaty && d4 != d1;
    is_beaty = is_beaty && d3 != d2;
    is_beaty = is_beaty && d3 != d1;
    is_beaty = is_beaty && d2 != d1;
    if (is_beaty) {
      // для красивого года печать и конец работы
      std::cout << b;
      break;
    }
  }
}
