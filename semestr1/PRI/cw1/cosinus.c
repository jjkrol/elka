/**************************************************************************
Autor:
Jakub Krol
Data:
27.10.2010
Opis:
Program liczacy wartosc cosinusa kata x z przyblizeniem n i liczacy
wartosc bledu wzglednego tego wyniku w stosunku do wartosci uzyskanej
przy pomocy funkcji bibliotecznej C
**************************************************************************/
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main(){
	double wynik=1;//wynik koncowy
	double czastkowy;//przechowuje i-ty element szeregu
	int i=1;//do petli for sumujacej szereg
	int n; //dokladnosc
	double x,oldx; //kat
	float blad;//wartosc bledu wzglednego
	int error;
	const double ludolfina=3.14159265351189793;//pi 
	system("clear");//wyczysc ekran
	printf("#########################################################\n");
	printf("# Program liczacy cosinus                               #\n");
	printf("#########################################################\n\n");
	printf("Podaj kat: ");//wczytywanie danej
	if(scanf("%lf",&x)!=1){//sprawdzanie poprawnosci
		error=1;
		}
	printf("Podaj dokladnosc: ");//wczytywanie danej
	if(scanf("%d",&n)!=1){//sprawdzanie poprawnosci
		error=1;
		}
	if(n<0||error==1){//sprawdzanie, czy liczba jest wieksze od zera
		printf("\nBlad!\n");
		exit(1);
		}
	printf("\nWprowadzone liczby to: %lf i %d\n",x,n);
	//redukcja kata do sensownego zakresu
	oldx=x;//zapisanie wprowadzonej zmiennej do uzycia w funkcji bibliotecznej
	if(fabs(x)>2*ludolfina){
		x=fmod(x,2*ludolfina);
		}
	printf("Kat zredukowany:\t %lf\n",x);	
	for(i=1;i<=n;i++){
		if(i==1){
			czastkowy=-x*x/2;//pierwszy element
			}
		else{
			czastkowy=-czastkowy*x*x/(2*i*(2*i-1));//n-ty element
			}
		if(fabs(czastkowy)<0.00000000000001){//sprawdzanie dokladnosci
			printf("Zbyt mala dokladnosc, koniec obliczen w kroku %d\n", i);
			break;
			}
		wynik=wynik+czastkowy;//zmiana koncowego wyniku o nowy element
		}
	printf("Wynik ostateczny:\t %lf \n",wynik);//wypisanie wyniku
	printf("Wynik z funkcji:\t %lf \n", cos(oldx));//wypisanie wyniku z funkcji bilbiotecznej
	blad=(wynik-cos(oldx))/cos(oldx)*100;//obliczenie bledu
	printf("Blad wzgledny:\t\t %f \n",blad);//wypisanie bledu
	return 0;
	}

