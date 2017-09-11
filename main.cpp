#include <iostream>
#include <string>
#include <fraction.h>

using namespace std;

int main() {

    // Create a bunch of fractions.
    Fraction frac1(4, 5);
    Fraction frac2(5, 8);
    Fraction frac3(1, 8);
    Fraction frac4(2, 3);
    Fraction frac5(1, 7);

    // Print them out.
    cout << "Fraction 1: " << frac1.get_string() << endl;
    cout << "Fraction 2: " << frac2.get_string() << endl;
    cout << "Fraction 3: " << frac3.get_string() << endl;
    cout << "Fraction 4: " << frac4.get_string() << endl;
    cout << "Fraction 5: " << frac5.get_string() << endl;
    cout << endl;

    // Print an equation we're testing.
    cout << "(" << frac1.get_string()
         << " - " << frac2.get_string()
         << " + " << frac3.get_string()
         << ") / (" << frac4.get_string()
         << " * " << frac5.get_string()
         << ")" << endl;

    // Calculate some intermediate results.
    Fraction frac_firstpar = frac1-frac2+frac3;
    Fraction frac_secondpar = frac4 * frac5;

    // Print the intermediate stage.
    cout << "(" << frac_firstpar.get_string()
         << ") / (" << frac_secondpar.get_string()
         << ")" << endl;

    // Simplify the intermediate stage.
    frac_firstpar.simplify();
    frac_secondpar.simplify();

    // Print the simplified form.
    cout << "(" << frac_firstpar.get_string()
         << ") / (" << frac_secondpar.get_string()
         << ")" << endl;

    // Calculate the final result.
    Fraction frac_final = frac_firstpar / frac_secondpar;

    // Print the unsimplified result
    cout << frac_final.get_string();

    // Simplify the final result
    frac_final.simplify();

    // Print the final result
    cout << " = " << frac_final.get_string() << endl;
    cout << endl;

    // Print some test results.

    cout << frac_final.get_numerator()
         << " / "
         << frac_final.get_denominator()
         << " ~= "
         << frac_final.get_double() << endl;

    // Print some negative fraction tests
    cout << Fraction(2, 3).get_string() << endl;
    cout << Fraction(-2, 3).get_string() << endl;
    cout << Fraction(2, -3).get_string() << endl;
    cout << Fraction(-2, -3).get_string() << endl;

    // Fraction equivalence tests
    cout << "Test 1 ";
    if (Fraction(2, 2) == Fraction(2, 2)) {
        cout << "ok";
    } else {
        cout << "failed";
    }
    cout << endl;

    cout << "Test 2 ";
    if (Fraction(2, 2) == Fraction(-2, -2)) {
        cout << "ok";
    } else {
        cout << "failed";
    }
    cout << endl;

    cout << "Test 3 ";
    if (Fraction(3, 6) == Fraction(7, 14)) {
        cout << "ok";
    } else {
        cout << "failed";
    }
    cout << endl;

    cout << "Test 4 ";
    if (Fraction(-9, 2) == Fraction(18, -4)) {
        cout << "ok";
    } else {
        cout << "failed";
    }
    cout << endl;

    cout << "Test 5 ";
    if (Fraction(1, 2) == Fraction(3, 4)) {
        cout << "failed";
    } else {
        cout << "ok";
    }
    cout << endl;


}
