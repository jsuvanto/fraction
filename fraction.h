#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/*!
 * \brief A class for creating fractions.
 * \author Juha Suvanto
 *
 * \note So far only the basic arithmetic (+, -, *, /) and the equivalence (==) operators are supported.
 */
class Fraction {
  public:

    // Constructors.

    /*!
     * \brief Default constructor.
     *
     * Creates a Fraction with numerator 1 and denominator 1.
     */
    Fraction();             // Fraction = 1/1


    /*!
     * \brief Integer constructor.
     * \param p An integer.
     *
     * Creates a Fraction with numerator p and denominator 1.
     */
    Fraction(int p);        // Fraction = p/1


    /*!
     * \brief Fraction constructor.
     * \param p The numerator.
     * \param q The denominator.
     * \pre q != 0
     * \post q > 0
     *
     * Creates a Fraction object with numerator p and denominator q. Sign 
     * of the fraction is only stored in the numerator.
     */
    Fraction(int p, int q); // Fraction = p/q


    // Methods


    /*!
     * \brief Gets a string representation of the fraction.
     * \return A string in the format "-p/q", where "-" stands for the 
     * sign in case of negative values, "p" is the numerator and "q" is 
     * the denominator.
     * \post String format is correct.
     */
    std::string get_string() const;


    /*!
     * \brief Gets the numerator of the fraction.
     * \return The numerator
     */
    int get_numerator() const;


    /*!
     * \brief Gets the denominator of the fraction.
     * \return The denominator.
     */
    int get_denominator() const;


    /*!
     * \brief Gets a decimal approximation of the fraction.
     * \return A decimal value.
     */
    double get_double() const;


    /*!
     * \brief Simplifies the fraction.
     * \post q > 0
     */
    void simplify();


    /*!
     * \brief Expands the fraction by a positive number.
     * \param expander The expander.
     * \pre expander > 0
     * \post Fraction is expanded.
     *
     * Multiplies the numerator and the denominator with expander.
     */
    void expand(int expander);


    // Operators


    /*!
     * \brief Sums two fractions
     * \param f A second fraction.
     * \return The unsimplified sum of two fractions.
     * \post q > 0
     */
    Fraction operator+(const Fraction& f) const;


    /*!
     * \brief Subtracts two fractions.
     * \param f A second fraction
     * \return The unsimplified difference of two fractions.
     * \post q > 0
     */
    Fraction operator-(const Fraction& f) const;


    /*!
     * \brief Multiplies two fractions together
     * \param f A second fraction.
     * \return The unsimplified product of two fractions.
     * \post q > 0
     */
    Fraction operator*(const Fraction& f) const;


    /*!
     * \brief Divides a fraction with another fraction.
     * \param f A second fraction.
     * \return The unsimplified quotient of two fractions.
     * \pre f != 0
     * \post q > 0
     */
    Fraction operator/(const Fraction& f) const;


    /*!
     * \brief Compares the equivalence of two fractions.
     * \param f A second fraction.
     * \return A boolean truth value.
     */
    bool operator==(const Fraction& f) const;


  private:
    int p_; // Numerator
    int q_; // Denominator
};

#endif // FRACTION_H
