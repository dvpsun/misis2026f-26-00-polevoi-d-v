// 2024 by Polevoy Dmitry
// source https://codeforces.com/problemset/problem/1352/A
// 1352A Сумма круглых чисел

#include <iostream>
#include <string>

int main() { 
  std::string s; // само число
  int t = 0;
  std::cin >> t;
  for (; 0 < t; t -= 1) {
    std::cin >> s;
    int c = 0;  // число ненулевых разрядов
    for (const auto& ch : s) {
       if ('0' != ch) {
         c += 1;
       }
    }
    std::cout << c << ' ';
    // распечатаем круглые слагаемые
    for (int i = 0, i_end = std::ssize(s); i < i_end; i += 1) {
       if ('0' != s[i]) {
         std::cout << s[i];
         for (int i_zero = i + 1; i_zero < i_end; i_zero += 1) {
           std::cout << '0';
         }
         std::cout << ' ';
       }
    }
  }

  return 0;
}