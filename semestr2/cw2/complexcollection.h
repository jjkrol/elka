#ifndef COMPLEXCOLLECTION_H
#define COMPLEXCOLLECTION_H
#include "myextendedcomplex.h"
#include <cstdlib>
template <class T>
class Complexcollection
{
    public:
        Complexcollection();
        virtual ~Complexcollection();
        void pushComplex(T);
        void printComplex();
        T getNthComplex(int);
        int getSize();
    protected:
    private:
    T *itsArray;
    int itsSize;
};
template <class T>
Complexcollection<T>::Complexcollection(){
    itsArray = NULL;
    itsSize = 0;
}

template <class T>
Complexcollection<T>::~Complexcollection(){
}

template <class T>
void Complexcollection<T>::pushComplex(T num){
itsArray = (T *) realloc (itsArray, (itsSize+1)*sizeof(T));
itsArray[itsSize++]=num;
}

template <class T>
void Complexcollection<T>::printComplex(){
for(int i=0;i<itsSize;i++){
cout<<i+1<<". "<<itsArray[i]<<endl;
}
}

template <class T>
int Complexcollection<T>::getSize(){
return itsSize;
}
template <class T>
T Complexcollection<T>::getNthComplex(int index){
return itsArray[index];
}

#endif // COMPLEXCOLLECTION_H
