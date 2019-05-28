#include "Polynomial.h"

Polynomial::Polynomial() : size(0), factors(nullptr) {}
Polynomial::Polynomial(const Polynomial& p) : Polynomial() {
    size = p.size;
    factors = new FComplex[size];
    for (size_t i = 0; i < size; i++) {
        factors[i] = FComplex{p.factors[i]};
    }
}
Polynomial::Polynomial(FComplex *v) : factors(v) {}
Polynomial::Polynomial(const initializer_list<FComplex> a) : size(0) {
    factors = new FComplex[a.size()];
    for (auto i : a) {
        factors[size] = i;
        size++;
    }
}
Polynomial::Polynomial(const char* s) : Polynomial() {
    fromString(s);
}
Polynomial::~Polynomial() {
    delete [] factors;
}

Polynomial& Polynomial::push_back(const FComplex& z) {
    resize(size + 1);
    factors[size-1] = z;
    return *this;
}
void Polynomial::set(const FComplex& z, size_t degree) {
    if (degree >= size)
        resize(degree + 1);
    factors[degree] = z;
}
FComplex Polynomial::get(size_t degree) const {
    if (degree >= size)
        return 0;
    return factors[degree];
}
void Polynomial::resize(size_t nsize) {
    if (size == nsize)
        return;
    FComplex *old = factors;
    factors = new FComplex[nsize];
    if (nsize > size) {
        for (size_t i = 0; i < size; i++)
            factors[i] = old[i];
        for (size_t i = size; i < nsize; i++)
            factors[i] = 0;
    }
    else {
        for (size_t i = 0; i < nsize; i++)
            factors[i] = old[i];
    }
    size = nsize;
    delete [] old;
}

FComplex Polynomial::calc(const FComplex& x) const {
    FComplex sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += factors[i] * x.power(i);
    return sum;
}
FComplex Polynomial::operator()(const FComplex& x) const {
    return calc(x);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    if (size < p.size)
        resize(p.size);
    for (size_t i = 0; i < p.size; i++)
        factors[i] += p.factors[i];
    return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p) {
    return *this += p * (-1);
}
Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial sum{*this};
    if (sum.size < p.size)
        sum.resize(p.size);
    for (size_t i = 0; i < p.size; i++)
        sum.factors[i] += p.factors[i];
    return sum;
}
Polynomial Polynomial::operator-(const Polynomial& p) const {
    return (*this) + (p * (-1));
}

Polynomial& Polynomial::operator*=(const FComplex& v) {
    for (size_t i = 0; i < size; i++)
        factors[i] *= v;
    return *this;
}
Polynomial& Polynomial::operator+=(const FComplex& v) {
    if (size > 0)
        factors[0] += v;
    else {
        resize(1);
        factors[0] = v;
    }
    return *this;
}
Polynomial& Polynomial::operator-=(const FComplex& v) {
    if (size > 0)
        factors[0] -= v;
    else {
        resize(1);
        factors[0] = v*(-1);
    }
    return *this;
}
Polynomial Polynomial::operator*(const FComplex& v) const {
    Polynomial mul{*this};
    for (size_t i = 0; i < mul.size; i++)
        mul.factors[i] *= v;
    return mul;
}
Polynomial Polynomial::operator+(const FComplex& v) const {
    Polynomial sum{*this};
    if (sum.size > 0)
        sum.factors[0] += v;
    else {
        sum.resize(1);
        sum.factors[0] = v;
    }
    return sum;
}
Polynomial Polynomial::operator-(const FComplex& v) const {
    return (*this) + (v*(-1));
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (&p == this)
        return *this;
    resize(p.size);
    for (size_t i = 0; i < size; i++)
        factors[i] = p.factors[i];
    return *this;
}

bool Polynomial::operator==(const Polynomial& p) {
    size_t lower = size;
    if (p.size > size) {
        for (size_t i = size; i < p.size; i++) {
            if (p.factors[i] != 0)
                return false;
        }
    }
    else if (size > p.size) {
        lower = p.size;
        for (size_t i = p.size; i < size; i++) {
            if (factors[i] != 0)
                return false;
        }
    }
    for (size_t i = 0; i < lower; i++) {
        if (factors[i] != p.factors[i])
            return false;
    }
    return true;
}
bool Polynomial::operator!=(const Polynomial& p) {
    return !(*this == p);
}

string Polynomial::ToString() const {
    if (size <= 0)
        return "";
    string s;
    for (int i = size-1; i > 0; i--) {
        if (factors[i].R()==0)
            continue;
        s.append(factors[i].ToString());
        s.append("z^");
        s.append(to_string(i));
        s.append(" + ");
    }
    s.append(factors[0].ToString());
    return s;
}
void Polynomial::fromString(const string& src) {
    string prep;
    prep.reserve(src.size());
    for (auto c : src) {
        if (c == 'x')
            prep.push_back('z');
        else if (c == '-') {
            prep.push_back('+');
            prep.push_back('-');
        }
        else if (c != ' ')
            prep.push_back(c);
    }
    regex rgx[6] = {regex("[(]{1}([0-9,.i+-])*[)]{1}z[0-9^]+"), regex("[(]{1}([0-9,.i+-])*[)]{1}z"), regex("[(]{1}([0-9,.i+-])*[)]{1}"), regex("([0-9,.-])*z[0-9^]+"), regex("([0-9,.-])*z"), regex("[0-9,.-]+")};
    smatch mch;
    size_t zpos = 0, d;
    for (size_t i = 0; i < 6; i++) {
        while (regex_search(prep, mch, rgx[i])) {
            d = 0;
            zpos = mch[0].str().find('z');
            if (zpos != string::npos) {
                d = 1;
                if (static_cast<int>(zpos) < mch[0].length()-2)
                    d = atoi(mch[0].str().substr(zpos+2).data());
                if (zpos > 0)
                    set(FComplex{mch[0].str().substr(0, zpos).data()}, d);
                else
                    set(1.0, d);
            }
            else
                set(FComplex{mch[0].str().data()}, d);
            prep = mch.prefix();
            prep.append(mch.suffix());
        }
    }
}

Polynomial::operator string() {
    return ToString();
}

FComplex* Polynomial::begin() {
    return factors;
}
FComplex* Polynomial::end() {
    return factors+size;
}