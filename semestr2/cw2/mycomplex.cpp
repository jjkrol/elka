#include "mycomplex.h"

using namespace std;
Mycomplex::Mycomplex(): // konstruktor bez argumentów
itsRe(0),itsIm(0){
//    cout<<"++konstruktor++"<<endl;
}

Mycomplex::Mycomplex(float Re, float Im):
itsRe(Re),itsIm(Im){ //konstruktor z argumentami
//    cout<<"++konstruktor++"<<endl;
}

Mycomplex::~Mycomplex(){ //destruktor
//cout<<"--destruktor--"<<endl;
}

void Mycomplex::setVals(float Re, float Im){ //ustaw wartoœci
    itsRe=Re;
    itsIm=Im;
}

/* dodawanie */
Mycomplex Mycomplex::operator+(const Mycomplex & num) const{
    Mycomplex sum(itsRe+num.getRe(),itsIm+num.getIm());
    return sum;
}
Mycomplex& Mycomplex::operator+=(const Mycomplex & num){
    itsRe+=num.getRe();
    itsIm+=num.getIm();
    return *this;
}

/* odejmowanie */
Mycomplex Mycomplex::operator-(const Mycomplex & num) const{
    Mycomplex diff(itsRe-num.getRe(),itsIm-num.getIm());
    return diff;
}
Mycomplex& Mycomplex::operator-=(const Mycomplex & num){
    itsRe-=num.getRe();
    itsIm-=num.getIm();
    return *this;
}

/* mnozenie */
Mycomplex Mycomplex::operator*(const Mycomplex & num) const{
    Mycomplex mult(itsRe*num.getRe()-itsIm*num.getIm(),itsIm*num.getRe()+itsRe*num.getIm());
    return mult;
}
Mycomplex& Mycomplex::operator*=(const Mycomplex & num){
    float oldRe=itsRe, oldIm=itsIm;;
    itsRe=oldRe*num.getRe()-oldIm*num.getIm();
    itsIm=oldIm*num.getRe()+oldRe*num.getIm();
    return *this;
}

/* dzielenie */
Mycomplex Mycomplex::operator/(const Mycomplex & num) const{//a+bi/c+di
    float numer1=itsRe*num.getRe()+itsIm*num.getIm(); //ac+bd
    float numer2=itsIm*num.getRe()-itsRe*num.getIm(); //bc-ad
    float denom=pow(num.getRe(),2)+pow(num.getIm(),2);//c^2+d^2
    Mycomplex div(numer1/denom,numer2/denom);
    return div;
}
Mycomplex& Mycomplex::operator/=(const Mycomplex & num){
    float numer1=itsRe*num.getRe()+itsIm*num.getIm(); //ac+bd
    float numer2=itsIm*num.getRe()-itsRe*num.getIm(); //bc-ad
    float denom=pow(num.getRe(),2)+pow(num.getIm(),2);//c^2+d^2
    itsRe=numer1/denom;
    itsIm=numer2/denom;
    return *this;
}

/* logiczne */
bool Mycomplex::operator==(const Mycomplex & num) const{
    return(itsRe==num.getRe())&&(itsIm==num.getIm());
}
bool Mycomplex::operator!=(const Mycomplex & num) const{
    return (itsRe!=num.getRe())||(itsIm!=num.getIm());
}

/* strumienie */
ostream & operator<<(ostream & os, const Mycomplex & num){
        os<<num.itsRe<<(num.itsIm>=0?"+":"")<<num.itsIm<<"j";
        return os;
    }

istream & operator>>(istream & is, Mycomplex & num){
    float Re,Im;
    int error=0;
    do{
    cout <<"Czesc rzeczywista: ";
    is >> Re;
        if(!is.good()){
            error=1;
            is.clear();
            is.sync();
            cout<<"Zle dane"<<endl;
        }
        else{
            error=0;
        }
    }while(error);

    do{
        cout <<"Czesc urojona: ";
        is >> Im;
        if(!is.good()){
            error=1;
            is.clear();
            is.sync();
            cout<<"Zle dane"<<endl;
        }
        else{
            error=0;
        }
    }while(error);
    num.itsRe=Re;
    num.itsIm=Im;
    return is;
}
