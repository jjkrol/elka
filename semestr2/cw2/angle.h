#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>

class angle
{
    public:
        angle(){};
        angle(float degrees){itsDegrees=degrees;}
        ~angle(){};
        friend std::ostream & operator<<(std::ostream & os, const angle & ang){os<<ang.itsDegrees<<"o";return os;}
        float getAngle(){return itsDegrees;}
    protected:
    private:
        float itsDegrees;
};

#endif // ANGLE_H
