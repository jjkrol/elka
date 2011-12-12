#include "main.h"
#include "interface.h"

int dzieci_size=0;
int katalogi_size=0;
int k2d_size=0;
dziecko puste_dziecko = {"puste","dziecko","pusta",0};
katalog pusty_katalog  = {"pusty"};
int main(){
/* init */
char komenda;

dzieci = (dziecko*) malloc(sizeof(dziecko) * ++dzieci_size);
katalogi = (katalog*) malloc(sizeof(katalog) * ++katalogi_size);
k2d = (para*) malloc(sizeof(para) * ++k2d_size);
katalogi[0]=pusty_katalog;
dzieci[0]=puste_dziecko;
k2d[0][0]=k2d[0][1]=0; // rekord 0 0

system("clear");//pusto na ekranie
pomoc();
while(1){
	printf("Wpisz komende(d/e/l/f/t/p/u/s/?/q):");
	scanf("%c", &komenda);
	czysc_bufor();
	system("clear");
	switch(komenda){
	case 'q':
		return 0;
	break;
	case 'd':
		dodaj();
	break;
	case 'l':
		lista();
	break;
	case 'e':
		edytuj();
	break;
	case 't':
		test();
	break;
	case 'f':
		file();
	break;
	case 'p':
		przenies();
	break;
	case 'u':
		usun();
	break;
	case 's':
		szukaj();
	break;
	default:
		pomoc();
	break;
	}
}

free(k2d);
free(dzieci);
free(katalogi);
return 0;
}

void test(){
int i;
printf("dzieci_size: %d\nkatalogi_size: %d\nk2d_size: %d\n", dzieci_size,katalogi_size,k2d_size);
printf("Katalogi:\n");
for (i=0;i<katalogi_size;i++){
	printf("%d:\t %s\n", i, katalogi[i].nazwa);
	}

printf("\nDzieci:\n");
for (i=0;i<dzieci_size;i++){
	printf("%d:\t %s\t%s\t%d\t%s\n", i, dzieci[i].imie, dzieci[i].nazwisko,dzieci[i].rok,dzieci[i].grupa);
	}

printf("\nK2D:\n");
for(i=0; i<k2d_size;i++){
	printf("%s : %s %s\n", katalogi[k2d[i][0]].nazwa, dzieci[k2d[i][1]].imie, dzieci[k2d[i][1]].nazwisko);
	}
}

void czysc_bufor(){
	while(getchar()!='\n');
//	fflush(stdin);
	}


/* *********************************** DODAWANIE ********************************** */
int dziecko_dodaj (dziecko defaultdata,int wymuszony_index){
//dane osobowe
int index;
if (wymuszony_index==0){//jesli dodajemy
	dzieci = (dziecko*) realloc(dzieci,sizeof(dziecko) * ++dzieci_size);
	index=dzieci_size-1;
	}
else{//jesli edytujemy
	index = wymuszony_index;
	}
	

//imie
printf("Podaj imie [%s]: ",!strcmp(defaultdata.imie,puste_dziecko.imie)?"":defaultdata.imie);
scanf("%20s",dzieci[index].imie);
czysc_bufor();
//nazwisko
printf("Podaj nazwisko [%s]: ",!strcmp(defaultdata.nazwisko,puste_dziecko.nazwisko)?"":defaultdata.nazwisko);
scanf("%30s",dzieci[index].nazwisko);
czysc_bufor();
//grupa
printf("Podaj grupe [%s]: ",!strcmp(defaultdata.grupa,puste_dziecko.grupa)?"":defaultdata.grupa);
scanf("%20s", dzieci[index].grupa);
czysc_bufor();
//data urodzenia
	int tempint;
do{
	printf("Podaj date urodzenia [%d]:",defaultdata.rok==puste_dziecko.rok?0:defaultdata.rok);
	tempint=scanf("%d", &dzieci[index].rok);
	czysc_bufor();
	printf("%s",(tempint>0)&&(tempint<=9999)?"":"zly format daty\n");
	}
	while(tempint!=1);
/*//katalog
char temp[20];
int katalogindex=0;
do {
printf("Podaj numer katalogu/[d]odaj nowy katalog/[l]ista katalogow: ");
scanf("%s",temp); 
if(temp[0]=='d'){
katalogindex=katalog_dodaj(pusty_katalog,0);
}
else if(temp[0]=='l'){
printf("lista katalogow\n");
}
else{//sprawdzic, czy taki istnieje
katalogindex=atoi(&temp);
}
}
while(katalogindex==0);
//wpis do glownego rejestru
k2d = (para*) realloc(k2d,sizeof(para) * ++k2d_size);
printf("k2d[%d] staje sie para: %d, %d\n",k2d_size-1,katalogindex,index);
k2d[k2d_size-1][0]=katalogindex;
k2d[k2d_size-1][1]=index;*/
return index;
}

int katalog_dodaj (katalog defaultdata, int wymuszony_index){
//dane osobowe
int index;
if (wymuszony_index==0){//jesli dodajemy
	katalogi = (katalog*) realloc(katalogi,sizeof(katalog) * ++katalogi_size);
	index=katalogi_size-1;
	}
else{//jesli edytujemy
	index = wymuszony_index;
	}
//nazwa
printf("Podaj nazwe [%s]: ",!strcmp(pusty_katalog.nazwa,defaultdata.nazwa)?"":defaultdata.nazwa);
scanf("%20s",katalogi[index].nazwa);
czysc_bufor();
return index;
}
/* ************************ EDYTOWANIE  ************************* */
int dziecko_edytuj(int index){
return dziecko_dodaj(dzieci[index], index);
}
int katalog_edytuj(int index){
return katalog_dodaj(katalogi[index],index);
}
/* ************************ USUWANIE    ************************* */
int dziecko_usun(int index){
dziecko *temparr;
dzieci_size--;
temparr = (dziecko*) malloc(sizeof(dziecko) * dzieci_size);
int i,j;
printf("Usuwanie z K2D\n");
for (i=1;i<katalogi_size;i++){
		dziecko_usunzkatalogu(index,i);
	}
for(i=0;i<dzieci_size;i++){
	if(i<index){
		temparr[i]=dzieci[i];
			}
	else{
		for (j=1;j<k2d_size;j++){
			if(k2d[j][1]==i+1){
				k2d[j][1]=i;
				}
			}
		temparr[i]=dzieci[i+1];
		}
	}
free(dzieci);
//dzieci = (dziecko*) malloc(sizeof(dziecko) * dzieci_size);
dzieci = temparr;
//free(temparr);
return 1;
}
int katalog_usun(int index){
katalog *temparr;
katalogi_size--;
temparr = (katalog*) malloc(sizeof(katalog) * katalogi_size);
int i,j;
printf("Usuwanie z K2D\n");
for (i=1;i<dzieci_size;i++){
		dziecko_usunzkatalogu(i,index);
	}
for(i=0;i<katalogi_size;i++){
	if(i<index){
		temparr[i]=katalogi[i];
			}
	else{
		for (j=1;j<k2d_size;j++){
			if(k2d[j][0]==i+1){
				k2d[j][0]=i;
				}
			}
		temparr[i]=katalogi[i+1];
		}
	}
free(katalogi);
katalogi = temparr;
return 1;
}
/* ************************ WYPISYWANIE ************************* */
void dziecko_lista(){
printf("\nDzieci:\n");
printf("id\t %20s\t\t\t %30s\t\t\t rok\t grupa\n","imie","nazwisko");
int i;
for (i=1;i<dzieci_size;i++){
	printf("%d:\t %20s\t\t\t%30s\t\t\t%d\t%s\n", i, dzieci[i].imie, dzieci[i].nazwisko,dzieci[i].rok,dzieci[i].grupa);
	}
}

void katalog_lista(){
printf("Katalogi:\n");
printf("id\t nazwa\n");
int i;
for (i=1;i<katalogi_size;i++){
	printf("%d:\t %s\n", i, katalogi[i].nazwa);
	}
}

void dziecko_wypisz(int index){
printf("Id: %d\n", index);
printf("Imie: %s\n",dzieci[index].imie);
printf("Nazwisko: %s\n",dzieci[index].nazwisko);
printf("Rok: %d\n",dzieci[index].rok);
printf("Grupa: %s\n",dzieci[index].grupa);
//katalogi, w ktorych jest
printf("Katalogi:\n");
int i;
for (i=1;i<k2d_size;i++){
	if(k2d[i][1]==index){
		printf("%s\n",katalogi[k2d[i][0]].nazwa);
		}
	}
}

void katalog_wypisz(int index){
int *temparr;
temparr=malloc(sizeof(int));
printf("Id: %d\n",index);
printf("Nazwa: %s\n",katalogi[index].nazwa);
//dzieci w katalogu
printf("Dzieci w katalogu:\n");
int tmp,i,j,l,k=0;
for (i=1;i<k2d_size;i++){
	if(k2d[i][0]==index){
		temparr=realloc(temparr,sizeof(int)*(k+1));
		temparr[k]=k2d[i][1];
		k++;
		}
}
for (j=0;j<k;j++){
	for(l=j+1;l<k;l++){
		if(strcmp(dzieci[temparr[j]].nazwisko,dzieci[temparr[l]].nazwisko)>0){
			tmp=temparr[j];
			temparr[j]=temparr[l];
			temparr[l]=tmp;
		}
	}
}
for (i=0;i<k;i++){
	printf("%s %s\n",dzieci[temparr[i]].imie, dzieci[temparr[i]].nazwisko);
	}
}
/* ***************************** PRZENOSZENIE ************************ */
int dziecko_kopiuj(int iddziecka,int idkatalogu){
int i,zajete=0;
k2d = (para*) realloc(k2d,sizeof(para) * ++k2d_size);
for(i=0;i<k2d_size;i++){
	if(k2d[i][0]==idkatalogu && k2d[i][1]==iddziecka)zajete=1;
	}
if(!zajete){
	k2d[k2d_size-1][0]=idkatalogu;
	k2d[k2d_size-1][1]=iddziecka;
	return 1;
}
else{
	return 0;
}

}

int dziecko_przenies(int iddziecka,int idzkatalogu,int iddokatalogu){
if(dziecko_kopiuj(iddziecka,iddokatalogu)>0){
	dziecko_usunzkatalogu(iddziecka,idzkatalogu);
	return 1;
}
else{
	return 0;
}
}

int dziecko_usunzkatalogu(int iddziecka,int idkatalogu){
int i;
int breakpoint=0;
para *temparr;
temparr = (para*) malloc(sizeof(para) * k2d_size-1);
for(i=0;i<k2d_size;i++){
	if (k2d[i][0]==idkatalogu && k2d[i][1]==iddziecka){
			breakpoint=1;
		}
	if(!breakpoint){
			temparr[i][0]=k2d[i][0];
			temparr[i][1]=k2d[i][1];
			}
	else{
		temparr[i][0]=k2d[i+1][0];
		temparr[i][1]=k2d[i+1][1];
		}
	}
if(breakpoint){
	k2d_size--;
	free(k2d);
	k2d = (para*) malloc(sizeof(para) * k2d_size);
	k2d = temparr;
	}
return 1;
}
/* ***************************** PLIKI    ********************************* */
int dane_otworz(char nazwa[30]){
	FILE *fp;
	char* buffer=0;
	char tokens[]="|\n";
	dziecko *temparr;
	dziecko tempdziecko;
	katalog *temparr2;
	katalog tempkatalog;
	para *temparr3;
	buffer = malloc(100);
	if((fp=fopen(nazwa,"r"))==NULL){
		printf("Nie mozna otworzyc pliku %s\n", nazwa);
		}
	else{
		printf("Otwieranie pliku %s...\n",nazwa);
		if(strncmp(nazwa,"pozycje",7)==0){
			dzieci_size=0;
			temparr = (dziecko*) malloc(sizeof(dziecko) * ++dzieci_size);
			temparr[0]=puste_dziecko;
			while(fgets(buffer, 100, fp)){
				temparr = (dziecko*) realloc(temparr,sizeof(dziecko) * ++dzieci_size);
				strcpy(tempdziecko.imie,strtok(buffer,tokens));
				strcpy(tempdziecko.nazwisko,strtok(NULL,tokens));
				strcpy(tempdziecko.grupa,strtok(NULL,tokens));
				tempdziecko.rok=atoi(strtok(NULL,tokens));
				printf("Wczytywane dziecko:: %s %s\n",tempdziecko.imie,tempdziecko.nazwisko);
				temparr[dzieci_size-1]=tempdziecko;				
				}
			free(dzieci);
			dzieci=temparr;
		}
		else if(strncmp(nazwa,"katalog",7)==0){
			katalogi_size=0;
			temparr2 = (katalog*) malloc(sizeof(katalog) * ++katalogi_size);
			temparr2[0]=pusty_katalog;
			while(fgets(buffer, 100, fp)){
				temparr2 = (katalog*) realloc(temparr2,sizeof(katalog) * ++katalogi_size);
				strcpy(tempkatalog.nazwa,strtok(buffer,tokens));
				printf("Wczytywany katalog: %s\n",tempkatalog.nazwa);
				temparr2[katalogi_size-1]=tempkatalog;				
				}
			free(katalogi);
			katalogi=temparr2;
		}		
		else if(strncmp(nazwa,"lacza",5)==0){
			k2d_size=0;
			temparr3 = (para*) malloc(sizeof(para) * ++k2d_size);
			temparr3[0][0]=0;
			temparr3[0][1]=0;
			while(fgets(buffer, 100, fp)){
				temparr3 = (para*) realloc(temparr3,sizeof(para) * ++k2d_size);
				temparr3[k2d_size-1][0]=atoi(strtok(buffer,tokens));
				temparr3[k2d_size-1][1]=atoi(strtok(NULL,tokens));
				printf("Wczytywana relacja: %d - %d\n",temparr3[k2d_size-1][0],temparr3[k2d_size-1][1]);
				}
			free(k2d);
			k2d=temparr3;
		}
		else{
			printf("nazwa pliku powinna zaczynac sie od pozycje/katalog/lacza\n");	
		}
		fclose(fp);
		}
	return 1;
	}
int dane_zapisz(char nazwa[30]){
	FILE *fp;
	char dziecko_linia[100];
	char katalog_linia[32];
	char k2d_linia[13];//ograniczenie wielkosci id
	char data[4];
	char lewa[5];//z k2d
	char prawa[5];//z k2d
	int i;
	if((fp=fopen(nazwa,"w"))==NULL){
		printf("Nie mozna otworzyc pliku %s\n", nazwa);
		}
	else{
		printf("Zapisywanie do pliku %s...\n",nazwa);
		if(strncmp(nazwa,"pozycje",7)==0){
			for(i=1;i<dzieci_size;i++){
				memset(dziecko_linia,0,100*sizeof(char));
				printf("Zapisywane dziecko nr %d... ", i);
				strcat(dziecko_linia,dzieci[i].imie);
				strcat(dziecko_linia,"|");
				strcat(dziecko_linia,dzieci[i].nazwisko);
				strcat(dziecko_linia,"|");
				strcat(dziecko_linia,dzieci[i].grupa);
				strcat(dziecko_linia,"|");
				sprintf(data,"%d",dzieci[i].rok);
				strcat(dziecko_linia,data);
				strcat(dziecko_linia,"\n");
				fputs(dziecko_linia,fp);
				printf(" zapisano\n");
				}
		}
		else if(strncmp(nazwa,"katalog",7)==0){
			for(i=1;i<katalogi_size;i++){
				memset(katalog_linia,0,32*sizeof(char));
				printf("Zapisywany katalog nr %d\n", i);
				strcat(katalog_linia,katalogi[i].nazwa);
				strcat(katalog_linia,"\n");
				fputs(katalog_linia,fp);
				}
		}		
		else if(strncmp(nazwa,"lacza",5)==0){
			for(i=1;i<k2d_size;i++){
				memset(k2d_linia,0,13*sizeof(char));
				printf("Zapisywana relacja %d - %d\n", k2d[i][0],k2d[i][1]);
				sprintf(lewa,"%d",k2d[i][0]);
				strcat(k2d_linia,lewa);
				strcat(k2d_linia,"|");
				sprintf(prawa,"%d",k2d[i][1]);
				strcat(k2d_linia,prawa);
				strcat(k2d_linia,"\n");
				fputs(k2d_linia,fp);
				}
		}
		else{
			printf("nazwa pliku powinna zaczynac sie od pozycje/katalog/lacza\n");	
		}
		fclose(fp);
		}	
	return 1;
	}
/* ***************************** SZUKANIE ********************************* */
//wykomentowane fragmenty kodu pozwalaja na stworzenie listy wynikow, ale tresc zadania tego nie wymaga
void dziecko_szukaj(char komenda, char zapytanie[30]){
	int i;
	int j=0;
/*	int *wyniki;
	wyniki=malloc(dzieci_size*sizeof(int));*/
switch(komenda){
	case 'i':
		for(i=1;i<dzieci_size;i++){
			if(strcmp(dzieci[i].imie,zapytanie)==0){
				printf("------------------------------\n");
				dziecko_wypisz(i);
				printf("------------------------------\n");
				j=1;
				//wyniki[j]=i;
				//j++;		
				}
		}
		printf(j?"":"Brak wynikow\n");
/*		printf("Wyniki:\n");
		for(i=0;i<j;i++){
			printf("id:%d\n",wyniki[i]);
			}*/
	break;
	case 'n':
		for(i=1;i<dzieci_size;i++){
			if(strcmp(dzieci[i].nazwisko,zapytanie)==0){
				printf("------------------------------\n");
				dziecko_wypisz(i);
				printf("------------------------------\n");
				j=1;
				}
		}
		printf(j?"":"Brak wynikow\n");
	break;
	case 'g':
		for(i=1;i<dzieci_size;i++){
			if(strcmp(dzieci[i].grupa,zapytanie)==0){
				printf("------------------------------\n");
				dziecko_wypisz(i);
				printf("------------------------------\n");
				j=1;
				}
		}
		printf(j?"":"Brak wynikow\n");
	break;
	case 'r':
		for(i=1;i<dzieci_size;i++){
			if(dzieci[i].rok==atoi(zapytanie)){
				printf("------------------------------\n");
				dziecko_wypisz(i);
				printf("------------------------------\n");
				j=1;
				}
		}
		printf(j?"":"Brak wynikow\n");
	break;

}


}
