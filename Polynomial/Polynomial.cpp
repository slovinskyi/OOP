#include "Polynomial.h"
#include <iostream>
#include <sstream>
#include <iomanip>

std::string superscriptNumber(int x)
{
	static std::string superscriptDigits[] = {
		"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"
	};
	std::stringstream normal;
	normal << x;
	std::string s = normal.str();
 
	std::string result;
	for(std::size_t i = 0; i < s.size(); ++i)
    {
		if (isdigit(s[i]))
        {
			result.append(superscriptDigits[s[i] - '0']);
		}
	}
 
	return result;
}

Polynomial::Polynomial()
{
    for(int i = 0; i < 100; ++i)
    {
        coef[i] = 0;
        exp[i] = 0;
    }
}

void Polynomial::enterTerms(void)
{
    bool found = false;
    int numberOfTerms, c, e, term;
    std::cout << std::endl;
    std::cout << "Prosze wprowadzic liczbe wyrazow wielomianu: ";
    std::cin >> numberOfTerms;
    for(int n = 1; n <= numberOfTerms; ++n )
    {
        std::cout << std::endl;
        std::cout << "Prosze wprowadzic wspolczynnik: ";
        std::cin >> c;
        std::cout << "Prosze wprowadzic potege: ";
        std::cin >> e;
        if (c != 0)
        {
            if(e == 0)
            {
                coef[0] += c;
                continue;
            }
            for(term = 1; (term < 100) && (coef[term] != 0); ++term)
            if(e == exp[term])
            {
                coef[term] += c;
                exp[term] = e;
                found = true;
            }

            if (!found)
            {
                coef[term] += c;
                exp[term] = e;
            }
        }
    }
}

void Polynomial::printPolynomial(void) const
{
    int start;
    bool zero = false;
    if(coef[0])
    {
        std::cout << coef[0];
        start = 1;
        zero = true;
    }
    else 
    {
        if(coef[1])
        {
            std::cout << coef[1] << 'x'; 
            if((exp[1] != 0 ) && (exp[1] != 1))
            std::cout << superscriptNumber(exp[1]);
            zero = true;
        }
        start = 2;
    }
    for(int x = start; x < 100; ++x)
    {
        if(coef[x] != 0) 
        {
            std::cout << std::setiosflags(std::ios::showpos) << coef[x] << std::resetiosflags(std::ios::showpos) << 'x';
            if((exp[x] != 0) && (exp[x] != 1))
            std::cout << superscriptNumber(exp[x]);
            zero = true;
        }
    }
    if(!zero) std::cout << '0';
    std::cout << std::endl;
}

const Polynomial Polynomial::operator=(const Polynomial& r)
{
    exp[0] = r.exp[0];
    coef[0] = r.coef[0];
    for(int j = 1; j < 100; ++j)
    {
        if(r.exp[j] != 0)
        {
            exp[j] = r.exp[j];
            coef[j] = r.coef[j];
        }
        else 
        {
            if(exp[j] == 0) break;
            exp[j] = 0;
            coef[j] = 0;
        }
    }

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& r) const
{
    Polynomial tmp;
    int j;
    bool exponentExists;
    tmp.coef[0] = coef[0] + r.coef[0];
    for(j = 1; (j < 100) && (r.exp[j] != 0); ++j) 
    {
        tmp.coef[j] = r.coef[j];
        tmp.exp[j] = r.exp[j];
    }

    for(int x = 1; x < 100; ++x)
    {
        exponentExists = false;
        for(int t = 1; (t < 100) && (!exponentExists); ++t)
        if(exp[x] == tmp.exp[t])
        {
            tmp.coef[t] += coef[x];
            exponentExists = true;
        }
        if (!exponentExists)
        {
            tmp.exp[j] = exp[x];
            tmp.coef[j] += coef[x];
            ++j;
        }
    }

    return tmp;
}

Polynomial &Polynomial::operator+=(const Polynomial &r)
{
    *this = *this + r;
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& r) const
{
    Polynomial tmp;
    int j;
    bool exponentExists;
    tmp.coef[0] = coef[0] - r.coef[0];
    
    for(j = 1; (j < 100) && (exp[j] != 0); ++j) 
    {
        tmp.coef[j] = coef[j];
        tmp.exp[j] = exp[j];
    }

    for(int x = 1; x < 100; ++x)
    {
        exponentExists = false;
        for(int t = 1; (t < 100) && (!exponentExists); ++t)
            if(r.exp[x] == tmp.exp[t])
            {
                tmp.coef[t] -= r.coef[x];
                exponentExists = true;
            }
            if(!exponentExists)
            {
                tmp.exp[j] = r.exp[x];
                tmp.coef[j] -= r.coef[x];
                ++j;
            }
    }
    return tmp;
}

Polynomial &Polynomial::operator-=(const Polynomial& r)
{
    *this = *this - r;
    return *this;
}

void Polynomial::polynomialCombine(Polynomial& w)
{
    Polynomial tmp = w;
    int e;
    for(int x = 0; x < 100; ++x)
    {
        w.coef[x] = 0;
        w.exp[x] = 0;
    }

    for(int x = 1; x < 100; ++x)
    {
        e = tmp.exp[x];

        for(int y = x + 1; y < 100; ++y)
            if(e == tmp.exp[y])
            {
                tmp.coef[x] += tmp.coef[y];
                tmp.exp[y] = 0;
                tmp.coef[y] = 0;
            }
    }

    w = tmp;
}

Polynomial Polynomial::operator*(const Polynomial& r)
{
    Polynomial tmp;
    int j = 1;
    for(int x = 0; (x < 100) && (x == 0 || coef[x] != 0); ++x)
    {
        for(int y = 0; (y < 100) && (y == 0 || r.coef[y] != 0 ); ++y)
        {
            if(coef[x] * r.coef[y])
                if((exp[x] == 0) && (r.exp[y] == 0))
                    tmp.coef[0] += coef[x] * r.coef[y];
                else 
                {
                    tmp.coef[j] = coef[x] * r.coef[y];
                    tmp.exp[j] = exp[x] + r.exp[y];
                    ++j;
                }
        }
    }
    polynomialCombine(tmp);
    return tmp;
}

Polynomial &Polynomial::operator*=(const Polynomial& r)
{
    *this = *this * r;
    return *this;
}


