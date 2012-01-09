#include "main.h"
#include "interface.h"

/* ******************** FUNKCJE INTERFEJSU *************************** */
void dodaj(){
char komenda;
printf("Dodaj [d]ziecko/[k]atalog/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();
if(komenda=='d'){
	if(dziecko_dodaj(puste_dziecko, 0)>0) printf("Dziecko dodane\n");
	}
else if(komenda=='k'){
	if(katalog_dodaj(pusty_katalog, 0)>0) printf("Katalog dodany\n");
	}
else if(komenda=='w'){
	return;
	}
else{
	dodaj();
	return;
	}
return;
}

void edytuj(){
char komenda;
char temp[20];
printf("Edytuj [d]ziecko/[k]atalog/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();

if(komenda=='d'){
	do{
		printf("Podaj id dziecka/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if(atoi(temp)>0 && atoi(temp)<=dzieci_size){
			if(dziecko_edytuj(atoi(temp))>0)printf("Edycja zakonczona pomyslnie\n");
			}
		else if(temp[0]=='w'){
			edytuj();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='k'){
	do{
		printf("Podaj id katalogu/[l]ista katalogow/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if(atoi(temp)>0 && atoi(temp)<=katalogi_size){
			if(katalog_edytuj(atoi(temp))>0)printf("Eycja zakonczona pomyslnie\n");
			}
		else if(temp[0]=='w'){
			edytuj();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='w'){
	return;
	}
else{
	edytuj();
	}
return;
}

void lista(){
char komenda;
char temp[20];
printf("Wypisz [d]zieci/[k]atalogi/[z]awartosc katalogu/d[a]ne dziecka/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();

if(komenda=='d'){
	dziecko_lista();
	}
else if(komenda=='k'){
	katalog_lista();
	}
else if(komenda=='a'){
	do{
		int index;
		printf("Podaj id dziecka/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if((index=atoi(temp))>0 && atoi(temp)<=dzieci_size){
			dziecko_wypisz(index);
			}
		else if(temp[0]=='w'){
			lista();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='z'){
	do{
		int index;
		printf("Podaj id katalogu/[l]ista katalogow/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if((index=atoi(temp))>0 && atoi(temp)<=katalogi_size){
			katalog_wypisz(index);
			}
		else if(temp[0]=='w'){
			lista();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='w'){
	return;
	}
else{
	lista();
	}
return;
}

void przenies(){
char komenda;
char temp[20];
printf("[k]opiuj dziecko/[p]rzenies dziecko/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();
if(komenda=='k'){
	int iddziecka,idkatalogu;
	iddziecka = idkatalogu = 0;
	do{
		printf("Podaj id dziecka do skopiowania/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if((iddziecka=atoi(temp))>0 && atoi(temp)<=dzieci_size){
			}
		else{
			przenies();
			return;
			}
		}while(temp[0]=='l');
	do{
		printf("Podaj id katalogu docelowego/[l]ista katalogow/[w]roc:");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if((idkatalogu=atoi(temp))>0 && atoi(temp)<=katalogi_size){
			}
		else{
			przenies();
			return;
			}
		}while(temp[0]=='l');
	if (iddziecka >0 && idkatalogu >0 && iddziecka<=dzieci_size && idkatalogu<=katalogi_size){
		if(dziecko_kopiuj(iddziecka, idkatalogu)>0)printf("Dziecko skopiowane pomyslnie\n");
		else printf("Blad kopiowania\n");
		}
	}
else if(komenda=='p'){
	int iddziecka,idzkatalogu, iddokatalogu;
	iddziecka = idzkatalogu = iddokatalogu = 0;
	do{
		printf("Podaj id dziecka do przeniesienia/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if((iddziecka=atoi(temp))>0 && atoi(temp)<=dzieci_size){
			}
		else{
			przenies();
			return;
			}
		}while(temp[0]=='l');
	do{
		printf("Podaj id katalogu zrodlowego/[l]ista katalogow/[w]roc:");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if((idzkatalogu=atoi(temp))>0 && atoi(temp)<=katalogi_size){
			}
		else{
			przenies();
			return;
			}
		}while(temp[0]=='l');
	do{
		printf("Podaj id katalogu docelowego/[l]ista katalogow/[w]roc:");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if((iddokatalogu=atoi(temp))>0 && atoi(temp)<=katalogi_size){
			}
		else{
			przenies();
			return;
			}
		}while(temp[0]=='l');
	if (iddziecka >0 && iddokatalogu >0 && idzkatalogu >0 && iddziecka<=dzieci_size && iddokatalogu<=katalogi_size && idzkatalogu<=katalogi_size){
		if(dziecko_przenies(iddziecka, idzkatalogu, iddokatalogu)>0)printf("Dziecko przeniesione pomyslnie\n");
		else printf("Blad kopiowania\n");
		}
	}
else if(komenda=='w'){
	return;
	}
else{
	przenies();
	}
return;
}

void usun(){
char komenda;
char temp[20];
printf("Usun [d]ziecko/[k]atalog/dziecko [z] katalogu/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();

if(komenda=='d'){
	do{
		printf("Podaj id dziecka/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if(atoi(temp)>0 && atoi(temp)<=dzieci_size){
			if(dziecko_usun(atoi(temp))>0)printf("Dziecko usuniete pomyslnie\n");
			}
		else if(temp[0]=='w'){
			usun();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='k'){
	do{
		printf("Podaj id katalogu/[l]ista katalogow/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if(atoi(temp)>0 && atoi(temp)<=katalogi_size){
			if(katalog_usun(atoi(temp))>0)printf("Katalog usuniety pomyslnie\n");
			}
		else if(temp[0]=='w'){
			usun();
			return;
			}
		}while(temp[0]=='l');
	}
else if(komenda=='z'){
	int iddziecka,idkatalogu;
	iddziecka = idkatalogu = 0;
	do{
		printf("Podaj id dziecka do usuniecia/[l]ista dzieci/[w]roc: ");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			dziecko_lista();
			}
		else if((iddziecka=atoi(temp))>0 && atoi(temp)<=dzieci_size){
			}
		else if(temp[0]=='w'){
			usun();
			return;
			}
		}while(temp[0]=='l');
	do{
		printf("Podaj id katalogu z ktorego chcesz usunac dziecko/[l]ista katalogow/[w]roc:");
		scanf("%s", temp);
		czysc_bufor();
		if (temp[0]=='l'){
			katalog_lista();
			}
		else if((idkatalogu=atoi(temp))>0 && atoi(temp)<=katalogi_size){
			}
		else if(temp[0]=='w'){
			usun();
			return;
			}
		}while(temp[0]=='l');
	if (iddziecka >0 && idkatalogu >0){
		if(dziecko_usunzkatalogu(iddziecka, idkatalogu)>0)printf("Dziecko usuniete pomyslnie\n");
		}
	}
else if(komenda=='w'){
	return;
	}
else{
	usun();
	return;
	}
return;
}

void szukaj(){
char komenda;
char zapytanie[30];
do{
printf("Szukaj wg [i]mienia/[n]azwiska/[r]oku/[g]rupy/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();
}while(komenda!='i' && komenda!='n' && komenda!='r' && komenda !='g' && komenda!='w');
if(komenda=='w'){
	return;
	}
else{
	printf("Wpisz zapytanie: ");
	scanf("%30s", zapytanie);
	czysc_bufor();
	dziecko_szukaj(komenda, zapytanie);
	}
return;
}

void file(){
char komenda;
char nazwa[31];
do{
printf("[o]tworz/[z]apisz/[n]umer zestawu danych do otwarcia/n[u]mer zestawu danych do zapisania/[w]roc: ");
scanf("%c",&komenda);
czysc_bufor();
}while(komenda!='o' && komenda!='z' && komenda!='w' && komenda!='n' && komenda!='u');
if(komenda=='w'){
	return;
	}
else if(komenda=='o'){
	printf("Wpisz nazwe pliku: ");
	scanf("%30s", nazwa);
	czysc_bufor();
	dane_otworz(nazwa);
	}
else if(komenda=='n'){
	printf("Wpisz numer zestawu plikow: ");
	scanf("%10s", nazwa);
	czysc_bufor();
	char tempstr[30];
	char ext[4]=".txt";
	strcpy(tempstr,"pozycje");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_otworz(tempstr);
	strcpy(tempstr,"katalog");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_otworz(tempstr);
	strcpy(tempstr,"lacza");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_otworz(tempstr);
	}
else if(komenda=='u'){
	printf("Wpisz numer zestawu plikow: ");
	scanf("%10s", nazwa);
	czysc_bufor();
	char tempstr[30];
	char ext[4]=".txt";
	strcpy(tempstr,"pozycje");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_zapisz(tempstr);
	strcpy(tempstr,"katalog");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_zapisz(tempstr);
	strcpy(tempstr,"lacza");
	strcat(tempstr,nazwa);
	strcat(tempstr,ext);
	dane_zapisz(tempstr);
	}
else{
	printf("Nazwa pliku: ");
	scanf("%30s", nazwa);
	czysc_bufor();
	dane_zapisz(nazwa);
	}
	return;
}

void pomoc(){
printf("Pomoc:\n");
printf("--------------------------------------------\n\
d - dodaj: dziecko, katalog\n\
e - edytuj: dziecko, katalog\n\
l - wypisz: dzieci, katalogi, dane dziecka lub katalogu\n\
f - operacje z plikami - wczytywanie i zapisywania, takze zestawy danych\n\
    tzn. w przypadku istnienia trzech plikow: pozycje1.txt, katalog1.txt, lacza1.txt\n\
    mozna wpisac tylko liczbe (w tym przypadku 1)\n\
p - przenoszenie dzieci: kopiowanie dzieci do katalogow, przenoszenie pomiedzy\n\
    katalogami\n\
u - usuwanie dzieci i katalogow z rejestru, dzieci z katalogow\n\
s - szukanie wg imienia, nazwiska, grupy i roku\n\
q - wyjscie\n\
kazdy inny znak - ta pomoc\n");
}
