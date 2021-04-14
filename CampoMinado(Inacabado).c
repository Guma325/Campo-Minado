#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
	int i, j, ijogada, jjogada,x = 1;
	srand(time(NULL));
	// bomba == 10;
	do{
	printf("qual o tamanho do tabuleiro que deseja jogar?\n");
	scanf("%d%d", &i,&j);
	}while(i<0 && j<0);
	
	int matriz[i][j];
	int mostrarcasa[i][j];
	int cont = 0;
	
	int linha = 0, coluna = 0;

	for(linha = 0; linha<i; linha++){//printa a matriz
		for(coluna = 0; coluna<j; coluna++){
			
			matriz[linha][coluna] = rand() % 11;
		}
	}
	
	for(linha = 0; linha<i; linha++){
		for(coluna = 0; coluna<j; coluna++){
			mostrarcasa[linha][coluna] = 0;
		}
	}
	
	
	
	for(linha = 0; linha<i; linha++){
		for(coluna = 0; coluna<j; coluna++){
			if(matriz[linha][coluna] != 10){
				matriz[linha][coluna] = 0;
			}
			}
		}
	
	
	for(linha = 0; linha<i; linha++){
		for(coluna = 0; coluna<j; coluna++){
			if(matriz[linha][coluna] >= 10 && matriz[linha][coluna] <= 18){
					printf("|B");
					if(linha == i-1){
						matriz[linha-1][coluna]++;
						matriz[linha][coluna+1]++;
						matriz[linha][coluna-1]++;
						matriz[linha-1][coluna-1]++;
						matriz[linha-1][coluna+1]++;	
					}else if(coluna == j-1){
						matriz[linha+1][coluna]++;
						matriz[linha-1][coluna]++;	
						matriz[linha][coluna-1]++;
						matriz[linha-1][coluna-1]++;
						matriz[linha+1][coluna-1]++;
						
					}else if(linha == 0){
						matriz[linha+1][coluna]++;
						matriz[linha][coluna+1]++;
						matriz[linha][coluna-1]++;
						matriz[linha+1][coluna+1]++;
						matriz[linha+1][coluna-1]++;	
						
					}else if(coluna == 0){
						matriz[linha+1][coluna]++;
						matriz[linha-1][coluna]++;
						matriz[linha][coluna+1]++;
						matriz[linha+1][coluna+1]++;
						matriz[linha-1][coluna+1]++;
					}else{
						matriz[linha+1][coluna]++;
						matriz[linha-1][coluna]++;
						matriz[linha][coluna+1]++;
						matriz[linha][coluna-1]++;
						matriz[linha+1][coluna+1]++;
						matriz[linha-1][coluna-1]++;
						matriz[linha+1][coluna-1]++;
						matriz[linha-1][coluna+1]++;
						
					}
			}else{
				printf("| ");
			}
		}
		printf("|\n");
	}
	
	
	//gameplay:
	do{
	printf("escreva a posicao da jogada\n");
	scanf("%d", &ijogada);
	scanf("%d", &jjogada);
	
	ijogada = ijogada-1;
	jjogada = jjogada-1;
	if((matriz[ijogada][jjogada] >= 10)&&(matriz[ijogada][jjogada] <= 18)){
		printf("Voce Perdeu\n");
		x = 0;
	}
	mostrarcasa[ijogada][jjogada] = 1;
	for(linha = 0; linha<i; linha++){//printa a matriz
		for(coluna = 0; coluna<j; coluna++){
			if(mostrarcasa[linha][coluna] == 1){
				if((matriz[linha][coluna] >= 10)&&(matriz[linha][coluna] <= 18)){
					printf("|B");
					}
				else if((matriz[linha][coluna] >= 0)&&(matriz[linha][coluna] < 10)){
						printf("|%d", matriz[linha][coluna]);
						}else{
						printf("| ");
	
				}
				}else{
						printf("| ");
				}
				} 
		printf("|\n");
	}
	
	}while(x >0);
	
	
	
}
