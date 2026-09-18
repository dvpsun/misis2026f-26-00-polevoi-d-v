// 2022 by Polevoy Dmitry
// source https://codeforces.com/problemset/problem/1352/A
// 1352A Сумма круглых чисел

#include <array>
#include <iostream>

int main() { 
  int t = 0;
  std::cin >> t;
  const int nDigits = 10;
  std::array<int, nDigits> digits{0};
  for (int i = 0; i < t; i += 1) {
    int n = 0; // само число
    std::cin >> n;
    int c = 0;  // число ненулевых разрядов
    int factor = 1;
    // выделим разряд
    for (int iD = 0; iD < digits.size(); iD += 1) {
      digits[iD] = n / factor % 10;
      c += digits[iD] ? 1 : 0;
      factor *= 10;
    }
    std::cout << c << ' ';
    // распечатаем круглые слагаемые
    factor = 1;
    for (int iD = 0; iD < digits.size(); iD += 1) {
      if (digits[iD]) {
        std::cout << digits[iD] * factor << ' ';
      }
      factor *= 10;
    }
  }
}