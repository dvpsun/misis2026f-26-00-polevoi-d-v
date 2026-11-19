// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef STACKL_STACKL_HPP_20241203
#define STACKL_STACKL_HPP_20241203

#include <cstddef>
#include <cstdint>

class StackL final {
public:
  using T = std::uint8_t;
public:
  StackL() = default;

  StackL(const StackL& src);

  ~StackL() = default;
  
  StackL& operator=(const StackL& src);

  [[nodiscard]] bool is_empty() const noexcept;

  void pop() noexcept;

  void push(const T val);
  
  [[nodiscard]] T& top() &;

  [[nodiscard]] const T& top() const &;

  void clear() noexcept;

private:
  struct Node {
    T val = T();
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
};

#endif
