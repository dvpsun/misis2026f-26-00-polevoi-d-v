// 2022 by Polevoi Dmitry
// task source https://codeforces.com/problemset/problem/4/A
// 4A Арбуз

#include <iostream>

int main() {
  int w = 0; // вес арбуза
  std::cin >> w;
  if (0 == w % 2 && 2 < w) {
    // w предсатвимо в виде суммы двух отличных от нуля четных чисел
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}
