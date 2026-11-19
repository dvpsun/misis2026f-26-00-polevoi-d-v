// 2024 by Polevoi Dmitry under Unlicense

#include <queuea/queuea.hpp>

#include <algorithm>
#include <stdexcept>


std::ptrdiff_t QueueA::count() const {
  return is_empty() ? 0 : (tail_ + size_ - head_) % size_ + 1;
}


QueueA& QueueA::operator=(const QueueA& src) {
  if (this != &src) {
    std::ptrdiff_t count = src.count();
    if (0 == count) {
      head_ = -1;
    } else {
      if (size_ < count) {
        size_ = (count + 4) / 4 * 4;
        delete[] data_;
        data_ = new T[size_];
      }
      if (src.head_ < src.tail_) {
        std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
      }
      else {
        std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
        std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
      }
    head_ = 0;
      tail_ = count - 1;
    }
  }
  return *this;
}


QueueA::QueueA(const QueueA& src) {
  if (!src.is_empty()) {
    std::ptrdiff_t count = src.count();
    head_ = 0;
    tail_ = count - 1;
    size_ = (count + 4) / 4 * 4;
    data_ = new T[size_];
    if (src.head_ < src.tail_) {
       std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
    } else {
       std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
       std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
    }
  }
}


void QueueA::swap(QueueA&& src) noexcept {
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
}


QueueA::~QueueA() {
  delete[] data_;
}


bool QueueA::is_empty() const noexcept {
  return head_ < 0;
}


void QueueA::pop() noexcept {
  if (!is_empty()) {
    if (head_ != tail_) {
      head_ = (head_ + 1) % size_;
    } else {
      head_ = -1;
    }
  }
}


void QueueA::push(const T val) {
  if (nullptr == data_) {
    size_ = 2;
    data_ = new T[size_];
  } 
  if (is_empty()) {
    head_ = 0;
    tail_ = 0;
  } else {
    if (head_ == (tail_ + 1) % size_) {
      // resize
      T* buf = new T[size_ * 2];
      std::swap(buf, data_);
      if (head_ < tail_) {
        std::copy(buf + head_, buf + tail_ + 1, data_);
      } else {
        std::copy(buf + head_, buf + size_, data_);
        std::copy(buf, buf + tail_ + 1, data_ + tail_ - head_);
      }
      delete[] buf;
      size_ *= 2;
      tail_ = count();
    } else {
      tail_ = (tail_ + 1) % size_;
    }
  }
  data_[tail_] = val;
}
  

QueueA::T& QueueA::top() {
  if (is_empty()) {
    throw std::logic_error("QueueA - try get top form empty queue.");
  }
  return data_[head_];
}


const QueueA::T& QueueA::top() const {
  if (is_empty()) {
    throw std::logic_error("QueueA - try get top form empty queue.");
  }
  return data_[head_];
}


void QueueA::clear() noexcept {
    head_ = -1;
}
