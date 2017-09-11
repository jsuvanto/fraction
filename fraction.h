#ifndef FRACTION_H
#define FRACTION_H

/*!
 * \brief A class for creating fractions.
 * \author Juha Suvanto
 *
 * \note So far only the basic arithmetic (+, -, *, /) and the equivalence (==) operators are supported.
 */
class Fraction {
  public:

    // Constructors.
    Fraction();             // Fraction = 1/1
    Fraction(int p);        // Fraction = p/1
    Fraction(int p, int q); // Fraction = p/q

    // Methods
    std::string get_string();
    int get_numerator();
    int get_denominator();
    double get_double();
    void simplify();
    void expand(const int expander);

    // Operators
    Fraction operator+(const Fraction f);
    Fraction operator-(const Fraction f);
    Fraction operator*(const Fraction f);
    Fraction operator/(const Fraction f);
    bool operator==(Fraction f);

  private:
    int p_; // Numerator
    int q_; // Denominator
};


/*!
 * \brief Default constructor.
 *
 * Creates a Fraction with numerator 1 and denominator 1.
 */
Fraction::Fraction(): p_(1), q_(1) {
}

/*!
 * \brief Integer constructor.
 * \param p An integer.
 *
 * Creates a Fraction with numerator p and denominator 1.
 */
Fraction::Fraction(int p): p_(p), q_(1) {
}


/*!
 * \brief Fraction constructor.
 * \param p The numerator.
 * \param q The denominator.
 * \pre q != 0
 *
 * Creates a Fraction object with numerator p and denominator q.
 */
Fraction::Fraction(int p, int q): p_(p), q_(q) {
}


/*!
 * \brief Gets a string representation of the fraction.
 * \return A string "p/q" where p is the numerator and q is the denominator.
 *
 * If the fraction's value is negative, a minus sign is prepended.
 */
std::string Fraction::get_string() {
    std::string fract = "";
    // Sign of the fraction shall only printed once with the numerator.
    // This preserves the sign of both numerator and denominator, only the
    // string representation is affected!
    if (p_ * q_ < 0) {
        fract.append("-");
    }
    fract.append(std::to_string(abs(p_)));
    fract.append("/");
    fract.append(std::to_string(abs(q_)));
    return fract;
}


/*!
 * \brief Gets the numerator of the fraction.
 * \return The numerator
 */
int Fraction::get_numerator() {
    return p_;
}


/*!
 * \brief Gets the denominator of the fraction.
 * \return The denominator.
 */
int Fraction::get_denominator() {
    return q_;
}


/*!
 * \brief Gets a decimal approximation of the fraction.
 * \return A decimal value.
 */
double Fraction::get_double() {
    double fract = double(p_) / double(q_);
    return fract;
}


/*!
 * \brief Simplifies the fraction.
 * \post Fraction is simplified.
 */
void Fraction::simplify() {
    int a = p_;
    int b = q_;
    // Euclidean method for finding the greatest common divisor of a and b
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % a;
    }
    p_ = p_/a;
    q_ = q_/a;
}


/*!
 * \brief Expands the fraction.
 * \param expander The expander.
 * \post Fraction is expanded.
 *
 * Multiplies the numerator and the denominator with expander.
 */
void Fraction::expand(const int expander) {
    p_ = p_ * expander;
    q_ = q_ * expander;
}


/*!
 * \brief Sums two fractions
 * \param f A second fraction.
 * \return The unsimplified sum of two fractions.
 */
Fraction Fraction::operator+(const Fraction f) {
    int new_p = p_ * f.q_ + q_ * f.p_;  // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


/*!
 * \brief Substracts a fraction from another fraction.
 * \param f A second fraction.
 * \return The unsimplified difference of two fractions.
 */
Fraction Fraction::operator-(const Fraction f) {
    int new_p = p_ * f.q_ - q_ * f.p_;  // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


/*!
 * \brief Multiplies two fractions together
 * \param f A second fraction.
 * \return The unsimplified product of two fractions.
 */
Fraction Fraction::operator*(const Fraction f) {
    int new_p = p_ * f.p_;               // New numerator
    int new_q = q_ * f.q_;              // New denominator
    return Fraction(new_p, new_q);
}


/*!
 * \brief Divides a fraction with another fraction.
 * \param f A second fraction.
 * \return The unsimplified quotient of two fractions.
 */
Fraction Fraction::operator/(const Fraction f) {
    int new_p = p_ * f.q_;              // New numerator
    int new_q = q_ * f.p_;              // New denominator
    return Fraction(new_p, new_q);
}


/*!
 * \brief Compares the equivalence of two fractions.
 * \param f A second fraction.
 * \return A boolean truth value.
 */
bool Fraction::operator==(Fraction f) {
    simplify();
    f.simplify();
    if (p_ == f.p_ && q_ == f.q_) {
        return 1;
    } else {
        return 0;
    }
}

#endif // FRACTION_H
