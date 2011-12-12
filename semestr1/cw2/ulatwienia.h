void czysc_bufor(){
	while(getchar()!='\n');
//	fflush(stdin);
	}
void przesun(int tablica[], int i,int ddz){
	int j;	
	for(j=N-1;j>i;j--){
		tablica[j]=tablica[j-1];
		}
	tablica[i]=ddz;
}
int tak_czy_nie(){
	char c;	
	scanf("%c",&c);
	czysc_bufor();
	return c=='t' || c=='T' ? 1 : 0;
	}
