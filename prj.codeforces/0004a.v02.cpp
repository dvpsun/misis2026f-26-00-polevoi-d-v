// 2022 by Polevoi Dmitry
// task source https://codeforces.com/problemset/problem/4/A
// 4A Арбуз

#include <iostream>

int main() {
  int w = 0; // вес арбуза
  std::cin >> w;
  std::cout << (0 == w % 2 && 2 < w ? "YES\n" : "NO\n");
}
