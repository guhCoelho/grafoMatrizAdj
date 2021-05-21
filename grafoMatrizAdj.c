#include <stdio.h>
#include <stdlib.h>

#define max 8

int tamanho = 0, op;
int grafo[max];
int matz[max][max];

int grafoTamanho(){
    int tm;
    printf("Escolha a quantidade de vertices do grafo");
    scanf(%i, &tm);
    return tm;
}

void grafoInserir(){
    int num1, num2;
    printf("Escolha o vertice de origem entre 0 a %i", max -1);
    scanf("%i", &num1);
    printf("Escolha o vertice de origem entre 0 a %i", max -1);
    scanf("%i", &num2);
    
    if (num1 > tamanho-1 || num2 > tamanho-1){
        printf("\nOs vertices precisam ser menores que %i", tamanho);
    } else {
        if(num1 < 0 || num2 < 0) {
            printf("\nOs vertices precisam ser mmaiores que 0");
        }else{
            matz [num1][num2]=1;
            matz [num2][num1]=1;    
        }
    } 
}

void grafoRemove(){
    int num1, num2;
    printf("Escolha o vertice de origem entre 0 a %i", max -1);
    scanf("%i", &num1);
    printf("Escolha o vertice de origem entre 0 a %i", max -1);
    scanf("%i", &num2);
    
    if (num1 > tamanho-1 || num2 > tamanho-1){
        printf("\nOs vertices precisam ser menores que %i", tamanho);
    } else {
        if(num1 < 0 || num2 < 0) {
            printf("\nOs vertices precisam ser mmaiores que 0");
        }else{
            matz [num1][num2]=0;
            matz [num2][num1]=0;
        }
    } 
}

void grafoImprimir(){
    printf("Lista de vertices \n");
    int i;
    for (i=0; i<tamanho; i++){
        printf("%i", grafo[i]);
    }

    printf("\n\n");
}

void grafoImprimirMatriz(){
    printf("Matriz de adjacencias \n [\n");
    int i, j;
    for (i=0; i<tamanho; i++){
        for (j=0; j<tamanho; j++){
            printf("%i", matz[i][j]);
        }
        printf("\n");
    }
    printf("] \n\n");
}

void menuGrafo(){
    printf("\nEscolha a opçao: \n");
    printf("1 - inserir aresta\n");
    printf("2 - remover aresta\n");
    printf("3 - Sair\n");
}

int main(){
    
    while (tamanho <= 0 || tamanho > max){
        tamanho = grafoTamanho();
        if (tamanho <= 0 || tamanho > max){
            printf("Escolha um valor entre 1 e %i \n", max);
        } else {
            int i;
            for (i=0; i<tamanho; i++){
                grafo[i]=i;
            }
        }

    }

    while (op!=3){
        system("cls");
        grafoImprimir();
        grafoImprimirMatriz();
        menuGrafo();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            grafoInserir();
            break;
        case 2:
            grafoRemove();
            break;

        case 3:
            printf("Obrigado por utilizar o programa \n\n");
            break;
        
        default:
            printf("Entre com uma opçao valida!");
            break;
        }
        system("cls");
    }

    return 0;
}