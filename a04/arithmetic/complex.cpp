#include "complex.hpp"

namespace arithmetic {
// default
Complex::Complex() : real_(0), imag_(0) {}

// assign real to real_
Complex::Complex(double real) : real_(real), imag_(0) {}

// assign real to real_ & imag to imag_
Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

// get real num
double Complex::real() const { return real_; }

// get imag
double Complex::imag() const { return imag_; }

// Absolute value
double Complex::abs() const { return std::sqrt(real_ * real_ + imag_ * imag_); }

// Norm
double Complex::norm() const { return (real_ * real_ + imag_ * imag_); }

// Angle
double Complex::arg() const { return std::atan2(imag_, real_); }

// Conjugate
Complex Complex::conj() const { return {real_, -imag_}; }

// Negate
Complex Complex::operator-() const { return {-real_, -imag_}; }

// Unary plus
Complex Complex::operator+() const { return *this; }

// Substraction
Complex Complex::operator-(const Complex &other) const { return {real_ - other.real_, imag_ - other.imag_}; }

// addition
Complex Complex::operator+(const Complex &other) const { return {real_ + other.real_, imag_ + other.imag_}; }

// Multiplication
Complex Complex::operator*(const Complex &other) const {
    return {(real_ * other.real_ - imag_ * other.imag_), (real_ * other.imag_ + imag_ * other.real_)};
}

// Division
Complex Complex::operator/(const Complex &other) const {
    // helper c^2 + d^2
    double temp = other.real_ * other.real_ + other.imag_ * other.imag_;

    if (temp == 0) { throw std::invalid_argument("Division by zero in Complex::operator/()"); }

    return {(real_ * other.real_ + imag_ * other.imag_) / temp, // r
            (imag_ * other.real_ - real_ * other.imag_) / temp};
}

bool Complex::operator==(const Complex &other) const { return (real_ == other.real_ && imag_ == other.imag_); }

} // namespace arithmetic