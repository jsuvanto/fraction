#include <iostream>
#include "fraction.h"

using std::abs;
using std::string;
using std::to_string;

Fraction::Fraction(): p_(1), q_(1) {
}


Fraction::Fraction(int p): p_(p), q_(1) {
}


Fraction::Fraction(int p, int q): p_(p), q_(q) {
    p_ = abs(p_);       // Remove sign from both numerator
    q_ = abs(q_);       // and denominator
    if (p * q < 0) {
        p_ = -p_;       // Return sign to numerator if necessary
    }
}


string Fraction::get_string() const{
    string fract = "";
    fract.append(to_string(p_));   // Numerator contains the sign
    fract.append("/");
    fract.append(to_string(q_));
    return fract;
}


int Fraction::get_numerator() const {
    return p_;
}


int Fraction::get_denominator() const {
    return q_;
}


double Fraction::get_double() const {
    double fract = double(p_) / double(q_);
    return fract;
}


void Fraction::simplify() {
    int a = p_;
    int b = q_;
    // Euclidean method for finding the greatest common divisor of a and b.
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % a;
    }
    p_ = p_/a;
    q_ = q_/a;
    // Change the sign from the denominator to the numerator.
    // This relies on the fact that if q_ is negative, p_ isn't.
    if (q_ < 0) {
        p_ = -p_;
        q_ = -q_;
    }
}


void Fraction::expand(const int expander) {
    p_ = p_ * expander;
    q_ = q_ * expander;
}


Fraction Fraction::operator+(const Fraction& f) const {
    int new_p = p_ * f.q_ + q_ * f.p_;  // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


Fraction Fraction::operator-(const Fraction& f) const {
    int new_p = p_ * f.q_ - q_ * f.p_;  // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


Fraction Fraction::operator*(const Fraction& f) const {
    int new_p = p_ * f.p_;               // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


Fraction Fraction::operator/(const Fraction& f) const {
    int new_p = p_ * f.q_;              // New numerator
    int new_q = q_ * f.p_;              // New denominator
    return Fraction(new_p, new_q);
}


bool Fraction::operator==(const Fraction& f) const {
    if (p_*f.q_ == q_*f.p_) {
        return 1;
    } else {
        return 0;
    }
}
