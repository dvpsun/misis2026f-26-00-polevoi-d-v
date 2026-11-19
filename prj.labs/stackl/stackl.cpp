// 2024 by Polevoi Dmitry under Unlicense

#include <stackl/stackl.hpp>

#include <memory>
#include <stdexcept>

StackL::StackL(const StackL& src) {
  if (!src.is_empty()) {
    head_ = new Node{src.head_->val};
    Node* p_src = src.head_;
    Node* p_dst = head_;
    while (p_src->next) {
      p_dst->next = new Node{p_src->next->val };
      p_src = p_src->next;
      p_dst = p_dst->next;
    }
  }
}

StackL& StackL::operator=(const StackL& src) {
  if (this != &src) {
    if (src.is_empty()) {
      clear();
    } else {
      Node* p_src = src.head_;
      if (is_empty()) {
        head_ = new Node{src.head_->val};
      } else {
        head_->val = src.head_->val;
      }
      Node* p_dst = head_;
      while (p_src->next) {
        if (p_dst->next) {
          p_dst->next->val = p_src->next->val;
        } else {
          p_dst->next = new Node{ p_src->next->val };
        }
        p_src = p_src->next;
        p_dst = p_dst->next;
      }
      if (p_dst->next) {
        Node* tail = p_dst->next;
        p_dst->next = nullptr;
        while (tail) {
          p_dst = tail->next;
          delete tail;
          tail = p_dst;
        }
      }
    }
  }
  return *this;
}

bool StackL::is_empty() const noexcept {
  return nullptr == head_;
}

void StackL::pop() noexcept {
  if (!is_empty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

void StackL::push(const T val) {
  head_ = new Node{val, head_};
}
  
StackL::T& StackL::top() & {
  if (is_empty()) {
    throw std::logic_error("StackL - try get top form empty stack.");
  }
  return head_->val;
}

const StackL::T& StackL::top() const & {
  if (is_empty()) {
    throw std::logic_error("StackL - try get top form empty stack.");
  }
  return head_->val;
}

void StackL::clear() noexcept {
  while (!is_empty()) {
    pop();
  }
}
