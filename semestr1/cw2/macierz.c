#include <stdio.h>
#define N 10 
#define M 10
int matrix[N][M]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int main(){
int i,j;
int temp;
for(i=0;i<N;i++){
	for(j=0;j<M;j++){
		printf("%d\t",matrix[i][j]);	
		}
	printf("\n");
}

printf("--------------------------\n");
for (i=0;i<N;i++){
	for(j=i;j<M;j++){
			temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
		}
	}
for (i=0;i<M;i++){
	for(j=0;j<N;j++){
		printf("%d\t",matrix[i][j]);
		}
	printf("\n");
	}
return 0;
}
