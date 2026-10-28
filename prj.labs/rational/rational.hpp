// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20241113
#define RATIONAL_RATIONAL_HPP_20241113

#include <cstdint>
#include <iosfwd>

class Rational {
public:
  Rational() = default;
  Rational(const Rational&) = default;
  Rational(Rational&&) = default; // сильно позже разберемся
  explicit Rational(const std::int32_t num) noexcept : num_(num) { }
  Rational(const std::int32_t num, const std::int32_t den);
  ~Rational() = default;
  Rational& operator=(const Rational&) = default;
  Rational& operator=(Rational&&) = default; // сильно позже разберемся

  [[nodiscard]] std::int32_t num() const noexcept { return num_; }
  [[nodiscard]] std::int32_t den() const noexcept { return den_; }

  [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int32_t rhs) noexcept;
  Rational& operator-=(const int32_t rhs) noexcept;
  Rational& operator*=(const int32_t rhs) noexcept;
  Rational& operator/=(const int32_t rhs);

  //! \brief Форматированный вывод в поток ostrm рационального числа в виде num/den.
  //!
  //! \param[in,out] ostrm - поток
  //! \retval поток
  std::ostream& write_to(std::ostream& ostrm) const noexcept;

  //! \brief Форматированный ввод из потока istrm комплексного числа в виде num/den.
  //!
  //! \param[in,out] istrm - поток
  //! \retval поток
  std::istream& read_from(std::istream& istrm) noexcept;

private:
  std::int32_t num_ = 0; //!< числитель
  std::int32_t den_ = 1; //!< знаменатель, > 0

  void normalize() noexcept;
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t rhs);

[[nodiscard]] Rational operator+(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int32_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif
