#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ // DZIECKO
	char imie[21];
	char nazwisko[31];
	char grupa[21];
	int rok;
	} dziecko;
typedef struct{ // KATALOG
	char nazwa[21];
	} katalog;
typedef int para[2]; // para do tablicy K2D
dziecko *dzieci; // tablica dzieci
katalog *katalogi; //tablica katalogi
//void *int[2] *k2d; 
para *k2d; //tablica K2D
extern int dzieci_size; //wielkosci tablic
extern int katalogi_size;
extern int k2d_size;
#ifndef PUSTE
#define PUSTE
#endif
extern dziecko puste_dziecko;
extern katalog pusty_katalog;
int dziecko_dodaj(dziecko defaultdata, int wymuszony_index);
int katalog_dodaj (katalog defaultdata, int wymuszony_index);
void czysc_bufor();
void test();
void dziecko_lista();
void katalog_lista();
void dziecko_wypisz(int index);
void katalog_wypisz(int index);
int dziecko_kopiuj(int iddziecka, int idkatalogu);
int dziecko_przenies(int iddziecka, int idzkatalogu, int iddokatalogu);
void dziecko_szukaj(char komenda, char zapytanie[30]);
int dziecko_usun(int index);
int katalog_usun(int index);
int dziecko_edytuj(int index);
int katalog_edytuj(int index);
int dziecko_usunzkatalogu(int iddziecka,int idkatalogu);
int dane_otworz(char nazwa[30]);
int dane_zapisz(char nazwa[30]);
// k2d (para*) malloc(sizeof(para) * size);
