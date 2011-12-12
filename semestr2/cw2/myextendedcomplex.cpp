#include "myextendedcomplex.h"
#include <cmath>
#define RADIANS( degrees ) ( degrees * 3.14159265 / 180 )
Myextendedcomplex::Myextendedcomplex(float absolute, angle degrees) : Mycomplex()
{
   itsAbsolute = absolute;
    itsDegrees = degrees;
    float Re=absolute*cos(RADIANS(degrees.getAngle()));
    float Im=absolute*sin(RADIANS(degrees.getAngle()));
    Mycomplex::setVals(Re,Im);
}

Myextendedcomplex::~Myextendedcomplex()
{
    //dtor
}
void Myextendedcomplex::setVals(float absolute, angle degrees){
   itsAbsolute = absolute;
    itsDegrees = degrees;
    float Re=absolute*cos(RADIANS(degrees.getAngle()));
    float Im=absolute*sin(RADIANS(degrees.getAngle()));
    Mycomplex::setVals(Re,Im);
}
ostream & operator<<(ostream & os, const Myextendedcomplex & num){
        os<<num.itsAbsolute<<"*e^(j*"<<num.itsDegrees<<") ["<<num.itsRe<<"+"<<num.itsIm<<"j]";
        return os;
    }
istream & operator>>(istream & is, Myextendedcomplex & num){
    float abs, kat;
    int error=0;
    do{
    cout <<"Modul: ";
    is >> abs;
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
        cout <<"Kat: ";
        is >> kat;
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
    num.setVals(abs, angle(kat));
    return is;
}
