// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUEA_QUEUEA_HPP_20241207
#define QUEUEA_QUEUEA_HPP_20241207

#include <cstddef>
#include <cstdint>

class QueueA final {
public:
  using T = std::int64_t;

  QueueA() = default;

  QueueA(const QueueA& src);

  ~QueueA();
  
  QueueA& operator=(const QueueA& src);

  [[nodiscard]] bool is_empty() const noexcept;

  void pop() noexcept;

  void push(const T val);
  
  [[nodiscard]] T& top();

  [[nodiscard]] const T& top() const;

  void clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;  //!< 
  T* data_ = nullptr;        //!< 
  std::ptrdiff_t head_ = -1; //!< 
  std::ptrdiff_t tail_ = -1; //!< 
private:
  std::ptrdiff_t count() const;
  void swap(QueueA&& src) noexcept;
};

#endif
