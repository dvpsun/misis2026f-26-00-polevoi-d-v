// Copyright 2022 by Polevoy Dmitry under Free Public License 1.0.0
// source https://codeforces.com/problemset/problem/1330/A

#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  for (int iT = 0; iT < t; iT += 1) {
    int n = 0;
    int x = 0;
    std::cin >> n >> x;
    std::vector<int> a(202, 0);
    int r = 0;
    for (int iN = 0; iN < n; iN += 1) {
      std::cin >> r;
      a[r] = 1;
    }
    int v = 0;
    for (int i = 1; i < a.size() && (a[i] || x); i += 1) {
      if (0 == a[i]) {
        a[i] = 1;
        x -= 1;
      }
      v += 1;
    }
    std::cout << v << '\n';
  }
}