#ifndef MYEXTENDEDCOMPLEX_H
#define MYEXTENDEDCOMPLEX_H
#include "angle.h"
#include "mycomplex.h"

class Myextendedcomplex : public Mycomplex
{
    public:
        Myextendedcomplex(){};
        Myextendedcomplex(float, angle);
        ~Myextendedcomplex();
        void setVals(float, angle);
        friend std::istream & operator>>(std::istream & is, Myextendedcomplex &);
        friend std::ostream & operator<<(std::ostream &, const Myextendedcomplex &);
    protected:
    private:
        angle itsDegrees;
        float itsAbsolute;
};

#endif // MYEXTENDEDCOMPLEX_H
