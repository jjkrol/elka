#include <iostream>
class Mycomplex{
public:
    Mycomplex();
    Mycomplex(float, float);
    ~Mycomplex();
    void setVals(float, float);
    float getRe()const{return itsRe;}
    float getIm()const{return itsIm;}
    Mycomplex operator+(const Mycomplex &) const;
    Mycomplex& operator+=(const Mycomplex &);
    Mycomplex operator-(const Mycomplex &) const;
    Mycomplex& operator-=(const Mycomplex &);
    Mycomplex operator*(const Mycomplex &) const;
    Mycomplex& operator*=(const Mycomplex &);
    Mycomplex operator/(const Mycomplex &) const;
    Mycomplex& operator/=(const Mycomplex &);
    bool operator==(const Mycomplex &) const;
    bool operator!=(const Mycomplex &) const;
    friend std::ostream & operator<<(std::ostream &, const Mycomplex &);
    friend std::istream & operator>>(std::istream & is, Mycomplex &);

private:
    float itsRe;
    float itsIm;
};
