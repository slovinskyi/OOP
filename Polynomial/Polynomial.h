#pragma once

class Polynomial
{

public:
    Polynomial();
    Polynomial operator+(const Polynomial& r) const;
    Polynomial operator-(const Polynomial& r) const;
    Polynomial operator*(const Polynomial& r);

    const Polynomial operator=(const Polynomial& r);

    Polynomial& operator+=(const Polynomial& r);
    Polynomial& operator-=(const Polynomial& r);
    Polynomial& operator*=(const Polynomial& r);

    void enterTerms(void);
    void printPolynomial(void) const;

    ~Polynomial() = default;

private:
    int exp[100];
    int coef[100];
    void polynomialCombine(Polynomial& r);
};