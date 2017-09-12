// The purpose of this file is to do some rudimentary tests to the class.

#include <iostream>
#include <fraction.h>

using namespace std;

int main() {

    // Create a bunch of fractions.
    Fraction frac1(1, 2);
    Fraction frac2(2, 4);
    Fraction frac3(4, -8);
    Fraction frac4(-2, 4);

    // Print them out.
    cout << "Fraction 1: " << frac1.get_string() << endl;
    cout << "Fraction 2: " << frac2.get_string() << endl;
    cout << "Fraction 3: " << frac3.get_string() << endl;
    cout << "Fraction 4: " << frac4.get_string() << endl;
    cout << endl;


    cout << endl << "Negative fractions:" << endl;
    cout << frac1.get_numerator() << " "
         << frac1.get_denominator() << " "
         << frac1.get_string() << endl;
    cout << frac2.get_numerator() << " "
         << frac2.get_denominator() << " "
         << frac2.get_string() << endl;
    cout << frac3.get_numerator() << " "
         << frac3.get_denominator() << " "
         << frac3.get_string() << endl;
    cout << frac4.get_numerator() << " "
         << frac4.get_denominator() << " "
         << frac4.get_string() << endl;

    cout << "Equivalence tests:" << endl;
    cout << "1==1: " << (frac1 == frac1) << endl;
    cout << "1==2: " << (frac1 == frac2) << endl;
    cout << "1==3: " << (frac1 == frac3) << endl;
    cout << "1==4: " << (frac1 == frac4) << endl;

    cout << "2==1: " << (frac2 == frac1) << endl;
    cout << "2==2: " << (frac2 == frac2) << endl;
    cout << "2==3: " << (frac2 == frac3) << endl;
    cout << "2==4: " << (frac2 == frac4) << endl;

    cout << "3==1: " << (frac3 == frac1) << endl;
    cout << "3==2: " << (frac3 == frac2) << endl;
    cout << "3==3: " << (frac3 == frac3) << endl;
    cout << "3==4: " << (frac3 == frac4) << endl;

    cout << "4==1: " << (frac4 == frac1) << endl;
    cout << "4==2: " << (frac4 == frac2) << endl;
    cout << "4==3: " << (frac4 == frac3) << endl;
    cout << "4==4: " << (frac4 == frac4) << endl;


    // Simplify tests

    frac1.simplify();
    frac2.simplify();
    frac3.simplify();
    frac4.simplify();

    cout << endl << "Simplify tests:" << endl;
    cout << frac1.get_numerator() << " "
         << frac1.get_denominator() << " "
         << frac1.get_string() << endl;
    cout << frac2.get_numerator() << " "
         << frac2.get_denominator() << " "
         << frac2.get_string() << endl;
    cout << frac3.get_numerator() << " "
         << frac3.get_denominator() << " "
         << frac3.get_string() << endl;
    cout << frac4.get_numerator() << " "
         << frac4.get_denominator() << " "
         << frac4.get_string() << endl;

    cout << "Equivalence tests after simplification:" << endl;
    cout << "1==1: " << (frac1 == frac1) << endl;
    cout << "1==2: " << (frac1 == frac2) << endl;
    cout << "1==3: " << (frac1 == frac3) << endl;
    cout << "1==4: " << (frac1 == frac4) << endl;

    cout << "2==1: " << (frac2 == frac1) << endl;
    cout << "2==2: " << (frac2 == frac2) << endl;
    cout << "2==3: " << (frac2 == frac3) << endl;
    cout << "2==4: " << (frac2 == frac4) << endl;

    cout << "3==1: " << (frac3 == frac1) << endl;
    cout << "3==2: " << (frac3 == frac2) << endl;
    cout << "3==3: " << (frac3 == frac3) << endl;
    cout << "3==4: " << (frac3 == frac4) << endl;

    cout << "4==1: " << (frac4 == frac1) << endl;
    cout << "4==2: " << (frac4 == frac2) << endl;
    cout << "4==3: " << (frac4 == frac3) << endl;
    cout << "4==4: " << (frac4 == frac4) << endl;

}
