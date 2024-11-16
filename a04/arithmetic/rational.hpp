#pragma once
#include <compare>
#include <cstdint>
#include <stdexcept>

namespace arithmetic {
/// A rational number.
///
/// A number of the form p/q for integer p and q.
class Rational {
private:
    int64_t numerator_;
    int64_t denominator_;

    /// @brief Get gcd of m and n to convert rational number to CCF
    /// @param m
    /// @param n
    /// @return gcd
    int64_t GCD(int64_t m, int64_t n) const;

public:
    /// Default constructor - the zero value.
    Rational();
    ///
    /// Construct a rational number equal to the given integer.
    /// @param value The in teger value.
    Rational(int64_t value);
    /// Construct a rational number from a numerator and a denominator.
    ///
    /// The returned rational is always in the canonical form.
    /// @param numerator The value of the numerator.
    /// @param denominator The value of the denominator.
    Rational(int64_t num, int64_t den);
    ///
    /// Numerator of the number.
    /// @return The numerator.
    int64_t num() const;
    ///
    /// Denominator of the number.
    /// @return The denominator.
    int64_t den() const;
    ///
    /// Explicit conversion to double.
    explicit operator double() const;
    ///
    /// Inverse of the rational.
    /// Equivalent to 1 / this.
    /// @return The inverse of this number.
    Rational inv() const;
    ///
    /// Negate the number.
    /// @return The negation of the number.
    Rational operator-() const;
    ///
    /// Unary plus
    /// This is a no-op.
    /// @return The same number.
    Rational operator+() const;
    ///
    /// Subtract another rational number.
    /// @param other The number to subtract.
    /// @return The result of subtracting this number from the other.
    Rational operator-(const Rational &other) const;
    ///
    /// Add another rational number.
    /// @param other The number to add.
    /// @return The result of adding this number to the other.
    Rational operator+(const Rational &other) const;
    ///
    /// Multiply by another rational number.
    /// @param other The number by which to multiply.
    /// @return The result of multiplying this number by the other.
    Rational operator*(const Rational &other) const;
    ///
    /// Divide by another rational number.
    /// Dividing by zero is undefined behavior.
    /// @param other The number to divide by.
    /// @return The result of dividing this number by the other.
    Rational operator/(const Rational &other) const;
    ///
    /// Three-way comparison.
    /// @param other The number to compare to.
    /// @return The strong_ordering result of the comparison.
    std::strong_ordering operator<=>(const Rational &other) const;
    ///
    /// Equality comparison.
    /// @param other The number to compare to.
    /// @return The bool result of the comparison.
    bool operator==(const Rational &other) const;
};
} // namespace arithmetic
