/*
Jakub Krol
2I2
Zadanie 2.2


*/
#include <fstream>
#include <string>
#include "angle.h"
#include "mycomplex.h"
#include "myextendedcomplex.h"
#include "complexcollection.h"
#define endl "\n"
int main()
{

#ifdef MENU
    /* INTERFACE */
    int inputType;
    int error;
do{
	system("clear");
    cout<<
    "Wybierz typ wprowadzania:"<<endl<<
    "1. czesc rzeczywista i urojona"<<endl<<
    "2. modul i kat"<<endl;
    cin >> inputType;
    inputType--;
    if(!cin.good() || (inputType>1) || (inputType<0)){
        error=1;
        cin.clear();
        cin.sync();
        cout<<"Zle dane"<<endl;
        }
    else{
        error=0;
    }
}while(error);

    Complexcollection<Myextendedcomplex> xkolekcja;
    Complexcollection<Mycomplex> kolekcja;



    int cmd;
do{
    do{
        cout << endl <<
        "1. Wprowadz liczbe"<<endl<<
        "2. Wypisz liczby"<<endl<<
        "3. Dodaj liczby"<<endl<<
        "4. Odejmij liczby"<<endl<<
        "5. Pomnoz liczby"<<endl<<
        "6. Podziel liczby"<<endl<<
        "7. Zakoncz program"<<endl;
        cin >> cmd;
        if(!cin.good() || (cmd>7)||(cmd<0) || (inputType && xkolekcja.getSize()<2 && cmd>2 && cmd<7) || (!inputType && kolekcja.getSize()<2 && cmd>2 && cmd<7)){
            error=1;
            cin.clear();
            cin.sync();
	    system("clear");
            cout<<"Zle dane"<<endl;
        }
        else{
            error=0;
        }
    }while(error);
system("clear");
    switch(cmd){
    case 1:
        if(inputType){
        Myextendedcomplex num;
        cin>>num;
        cout<<num;
        xkolekcja.pushComplex(num);
        cout<<"Zapisano"<<endl;
        }
        else{
        Mycomplex num;
        cin>>num;
        kolekcja.pushComplex(num);
        cout<<"Zapisano"<<endl;
        }
    break;
    case 2:
        if(inputType)xkolekcja.printComplex(); else kolekcja.printComplex();
    break;
	case 7:
    exit(1);
    break;
    case 3:
    case 4:
    case 5:
    case 6:

        cout<<"Wybierz pierwsza liczbe:"<<endl;
        int first,second;
        if(inputType){
        do{
            xkolekcja.printComplex();
            cin >> first;
            if(!cin.good()||(first<1)||(first>xkolekcja.getSize()+1)){error=1;cin.clear();cin.sync();cout<<"Zle dane"<<endl;}
            else{error=0;}
            }while(error);
        cout<<"Wybierz druga liczbe:"<<endl;
        do{
            xkolekcja.printComplex();
            cin >> second;
            if(!cin.good()||(second<1)||(second>xkolekcja.getSize()+1)){error=1;cin.clear();cin.sync();cout<<"Zle dane"<<endl;}
            else{error=0;}
            }while(error);
            cout<<xkolekcja.getNthComplex(first-1)<<endl;
            cout<<xkolekcja.getNthComplex(second-1)<<endl;
            Mycomplex wynik;
            switch(cmd){
                case 3:
                wynik = xkolekcja.getNthComplex(first-1) + xkolekcja.getNthComplex(second-1);
                cout<<"Wynik dodawania:"<<wynik<<endl;
                break;
                case 4:
                wynik = xkolekcja.getNthComplex(first-1) - xkolekcja.getNthComplex(second-1);
                cout<<"Wynik odejmowania:"<<wynik<<endl;
                break;
                case 5:
                wynik = xkolekcja.getNthComplex(first-1) * xkolekcja.getNthComplex(second-1);
                cout<<"Wynik mnozenia:"<<wynik<<endl;
                break;
                case 6:
                wynik = xkolekcja.getNthComplex(first-1) / xkolekcja.getNthComplex(second-1);
                cout<<"Wynik dzielenia:"<<wynik<<endl;
                break;
            }
        }
        else{
            do{
            kolekcja.printComplex();
            cin >> first;
            if(!cin.good()||(first<1)||(first>kolekcja.getSize()+1)){error=1;cin.clear();cin.sync();cout<<"Zle dane"<<endl;}
            else{error=0;}
            }while(error);
        cout<<"Wybierz druga liczbe:"<<endl;
        do{
            kolekcja.printComplex();
            cin >> second;
            if(!cin.good()||(second<1)||(second>kolekcja.getSize()+1)){error=1;cin.clear();cin.sync();cout<<"Zle dane"<<endl;}
            else{error=0;}
            }while(error);
            cout<<kolekcja.getNthComplex(first-1)<<endl;
            cout<<kolekcja.getNthComplex(second-1)<<endl;
            Mycomplex wynik;
            switch(cmd){
                case 3:
                wynik = kolekcja.getNthComplex(first-1) + kolekcja.getNthComplex(second-1);
                cout<<"Wynik dodawania:"<<wynik<<endl;
                break;
                case 4:
                wynik = kolekcja.getNthComplex(first-1) - kolekcja.getNthComplex(second-1);
                cout<<"Wynik odejmowania:"<<wynik<<endl;
                break;
                case 5:
                wynik = kolekcja.getNthComplex(first-1) * kolekcja.getNthComplex(second-1);
                cout<<"Wynik mnozenia:"<<wynik<<endl;
                break;
                case 6:
                wynik = kolekcja.getNthComplex(first-1) / kolekcja.getNthComplex(second-1);
                cout<<"Wynik dzielenia:"<<wynik<<endl;
                break;
            }
        }

    break;
    }
}while(cmd!=7);
#else
Complexcollection<Mycomplex> kolekcja;

    string line;
  ifstream file("dane.dat");
  if (file.is_open())
  {
    while ( file.good() )
    {
        char strre[20]="", strim[20]="";
        getline (file,line);
        int size=line.size();
        int dividerpos=(line.find_last_of('+')==-1)?line.find_last_of('-'):line.find_last_of('+');
        if(dividerpos<=0 && line[size-1]=='j')line.copy(strim,size-1); //tylko Im
        else if(dividerpos<=0 && line[size-1]!='j')line.copy(strre,size); //tylko Re
        else{
            line.copy(strim,size-dividerpos-1,dividerpos);
            line.copy(strre,dividerpos);
        }
        kolekcja.pushComplex(*(new Mycomplex(atof(strre),atof(strim))));
        cout<<"Dodano - Re: "<<atof(strre)<<" Im: "<<atof(strim)<<endl;
    }
    file.close();
    kolekcja.printComplex();

//dzialania - tylko dwa pierwsze elementy - prezentacyjnie:
Mycomplex pierwszy = kolekcja.getNthComplex(0);
Mycomplex drugi = kolekcja.getNthComplex(1);
Mycomplex wynik;
ofstream outfile;
outfile.open ("wynik.dat");
outfile<<"Liczba1: "<<pierwszy<<endl;
outfile<<"Liczba2: "<<drugi<<endl;
wynik=pierwszy+drugi;
outfile<<"Suma: "<<wynik<<endl;
wynik=pierwszy-drugi;
outfile<<"Roznica: "<<wynik<<endl;
wynik=pierwszy*drugi;
outfile<<"Iloczyn: "<<wynik<<endl;
wynik=pierwszy/drugi;
outfile<<"Iloraz: "<<wynik<<endl;
outfile.close();
}

  else cout << "Unable to open file";
#endif
//  cin>>liczba9;
    /*cin>>liczba1;
    cout<<"Liczba1: "<<liczba1<<endl;
    cout<<"Liczba2: "<<liczba1<<endl;
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
    cout << "Hello world!" << endl;*/
    return 0;
}
