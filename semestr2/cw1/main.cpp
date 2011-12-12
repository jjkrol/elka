#include "mycomplex.h"

using namespace std;
int main()
{
    Mycomplex liczba1;
    Mycomplex liczba2;
    Mycomplex liczba3;

    cin>>liczba1;
    cin>>liczba2;
    cout<<"Liczba1: "<<liczba1<<endl;
    cout<<"Liczba2: "<<liczba2<<endl;
        liczba3=liczba1+liczba2;
    cout<<"Suma: "<<liczba3<<endl;
        liczba3=liczba1-liczba2;
    cout<<"Roznica: "<<liczba3<<endl;
        liczba3=liczba1*liczba2;
    cout<<"Iloczyn: "<<liczba3<<endl;
        liczba3=liczba1/liczba2;
    cout<<"Iloraz: "<<liczba3<<endl;
    if (liczba1==liczba2){
        cout<<"1 i 2 sa sobie rowne"<<endl;
    }
    if (liczba1!=liczba3){
        cout<<"1 i 3 sa sobie nierowne"<<endl;
    }
    cout<<"-------------------------"<<endl;
    cout<<"Liczba1: "<<liczba1<<endl;
    cout<<"Liczba2: "<<liczba2<<endl;
        liczba1+=liczba2;
    cout<<"liczba1+=liczba2: "<<liczba1<<endl;
        liczba1-=liczba2;
    cout<<"liczba1-=liczba2: "<<liczba1<<endl;
        liczba1*=liczba2;
    cout<<"liczba1*=liczba2: "<<liczba1<<endl;
        liczba1/=liczba2;
    cout<<"liczba1/=liczba2: "<<liczba1<<endl;
    return 0;
}
