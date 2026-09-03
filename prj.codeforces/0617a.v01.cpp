// 2023 by Polevoy Dmitry
// task source https://codeforces.com/problemset/problem/617/A
// 617A Слоник

#include <iostream>

int main() {
  int x = 0;
  std::cin >> x;
  int n = x / 5;
  if (0 != n % 5) {
    n += 1;
  }
  std::cout << n << std::endl;
}
