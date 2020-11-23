#include <stdio.h>
#define SIZE 50

void printVectors(int* vetor, int* ocorrencias, unsigned int size){
    for(int i = 0; i < size; i++)
        if(ocorrencias[i] != 0)
            printf("%d %d\n", vetor[i], ocorrencias[i]);
}

int main(int argc, char* argv[]){
    int vetor[SIZE];
    int ocorrencias[SIZE];

    for(int i = 0; i < SIZE; i++)
        ocorrencias[i] = 0;

    for(int i = 0; i < SIZE; i++){
        int aux;
        int ocorreu = 0;
        scanf("%d ", &aux);

        for(int j = 0; j < i; j++){
            if(vetor[j] == aux){
                ocorrencias[j]++;
                ocorrencias[i] = 0;
                ocorreu=1;
                break;
            }else if (j == i-1){
                ocorreu=0;
            }
        }

        if (!ocorreu){
            vetor[i] = aux;
            ocorrencias[i] = 1;
        }
        
    }

    printVectors(vetor, ocorrencias, SIZE);

    return 0;
}