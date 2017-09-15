#include "fraction.h"

#include <iostream>

using std::abs;
using std::string;
using std::to_string;

Fraction::Fraction(): p_(1), q_(1) {
}


Fraction::Fraction(int p): p_(p), q_(1) {
}


Fraction::Fraction(int p, int q): p_(p), q_(q) {
    int sign = p*q/(abs(p*q);   // -1 if negative, 1 if positive.
    q_ = abs(q_);               // Remove sign from denominator.
    p_ = sign * abs(p_);        // Store sign in numerator.
}


string Fraction::get_string() const{
    string fract = "";
    fract.append(to_string(p_));    // Numerator contains the sign.
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
    return Fraction(p_/a, q_/a);
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
