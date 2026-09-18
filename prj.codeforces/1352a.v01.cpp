// 2022 by Polevoy Dmitry
// source https://codeforces.com/problemset/problem/1352/A
// 1352A Сумма круглых чисел

#include <iostream>

int main() { 
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n = 0;
    std::cin >> n;
    int d1 = n % 10;
    int d2 = n / 10 % 10;
    int d3 = n / 100 % 10;
    int d4 = n / 1000;
    int c = d1 ? 1 : 0;
    c += d2 ? 1 : 0;
    c += d3 ? 1 : 0;
    c += d4 ? 1 : 0;
    std::cout << c << ' ';
    if (d1) {
      std::cout << d1 << ' ';
    }
    if (d2) {
      std::cout << d2 * 10 << ' ';
    }
    if (d3) {
      std::cout << d3 * 100 << ' ';
    }
    if (d4) {
      std::cout << d4 * 1000 << ' ';
    }
  }
}