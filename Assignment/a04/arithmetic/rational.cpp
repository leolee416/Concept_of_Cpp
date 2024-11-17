#include "rational.hpp"
namespace arithmetic {
// default constructor
Rational::Rational() : numerator_(0), denominator_(1) {}

// Constructor with single integer value
Rational::Rational(int64_t value) : numerator_(value), denominator_(1) {}

// Constructor wiht two integer value
Rational::Rational(int64_t num, int64_t den) {
    if (den == 0) { throw std::invalid_argument("Denominator cannot be zero"); }

    int64_t gcd = GCD(num, den);

    if (den < 0) {
        num = -num;
        den = -den;
    }

    numerator_ = num / gcd;
    denominator_ = den / gcd;
}

// Get gcd of two numbers (m, n)
int64_t Rational::GCD(int64_t m, int64_t n) const {
    while (n != 0) {
        int64_t temp = m % n;
        m = n;
        n = temp;
    }
    if (n == 0) { return (m < 0) ? -m : m; }
    return (m < 0) ? -m : m;
}
// Get() numernator of rational number
int64_t Rational::num() const { return numerator_; }

// Get() denominator of rational number
int64_t Rational::den() const { return denominator_; }

// Convertion operator
Rational::operator double() const { return static_cast<double>(numerator_) / denominator_; }

// reverse the rational number
Rational Rational::inv() const {
    if (numerator_ == 0) { throw std::invalid_argument("Cannot compute the inverse of zero"); }
    return {denominator_, numerator_};
}
// Negate the number
Rational Rational::operator-() const { return {-numerator_, denominator_}; }

// Unary plus
Rational Rational::operator+() const { return *this; }

// Substruction
Rational Rational::operator-(const Rational &other) const {
    int64_t den{1};
    int64_t num{1};

    den = denominator_ * other.denominator_;
    num = numerator_ * other.denominator_ - other.numerator_ * denominator_;

    int64_t gcd = GCD(num, den);
    int64_t new_num = num / gcd;
    int64_t new_den = den / gcd;

    return {new_num, new_den};
}

Rational Rational::operator+(const Rational &other) const {
    int64_t den{1};
    int64_t num{1};

    den = denominator_ * other.denominator_;
    num = numerator_ * other.denominator_ + other.numerator_ * denominator_;

    int64_t gcd = GCD(num, den);
    int64_t new_num = num / gcd;
    int64_t new_den = den / gcd;

    return {new_num, new_den};
}

Rational Rational::operator*(const Rational &other) const {
    int64_t den = denominator_ * other.denominator_;
    int64_t num = numerator_ * other.numerator_;

    int64_t gcd = GCD(num, den);
    int64_t new_num = num / gcd;
    int64_t new_den = den / gcd;

    return {new_num, new_den};
}

Rational Rational::operator/(const Rational &other) const {
    if (other.numerator_ == 0) { throw std::invalid_argument("Divide 0 is undefined behavier"); }
    int64_t den = denominator_ * other.numerator_;
    int64_t num = numerator_ * other.denominator_;

    int64_t gcd = GCD(num, den);
    int64_t new_num = num / gcd;
    int64_t new_den = den / gcd;

    return {new_num, new_den};
}

std::strong_ordering Rational::operator<=>(const Rational &other) const {
    __int128_t lhs = static_cast<__int128_t>(numerator_) * static_cast<__int128_t>(other.denominator_);
    __int128_t rhs = static_cast<__int128_t>(other.numerator_) * static_cast<__int128_t>(denominator_);

    if (lhs < rhs) { return std::strong_ordering::less; }
    if (lhs > rhs) { return std::strong_ordering::greater; }
    return std::strong_ordering::equal;
}

bool Rational::operator==(const Rational &other) const {
    return (numerator_ * other.denominator_) == (other.numerator_ * denominator_);
}

} // namespace arithmetic
