#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 14

void quicksort (int vetorq[], int esquerda, int direita){
    int pivo = esquerda; 
    int posicaoq, menor, auxiliar, i;

    for(posicaoq = (esquerda + 1); posicaoq <= direita; posicaoq++){
        auxiliar = posicaoq;
        if(vetorq[auxiliar] < vetorq[pivo]){
            menor = vetorq[auxiliar];
            while(auxiliar > pivo){
                vetorq[auxiliar] = vetorq[auxiliar - 1];
                auxiliar--;
            }
            vetorq[auxiliar] = menor;
            pivo++;
        }
    }
    if((pivo - 1) >= esquerda){
        quicksort(vetorq, esquerda, pivo - 1);
    }
    if((pivo + 1) <= direita){
        quicksort(vetorq, (pivo + 1), direita);
    }
}
int buscaBinaria(int vetor[], int key, int left, int right){
    int mid;
    if(right < left){
        return -1;
    }

    mid = (left + right) / 2;
    if(vetor[mid] == key){
        return mid;
    }else if( key < vetor[mid]){
        return buscaBinaria(vetor, key, left, mid - 1);
    }else{
        return buscaBinaria(vetor, key, mid + 1, right);
    }

}

int main(){
    int posicao, resp, pos;
    int vetor[tam] = {45, 7, 10, 4, 13, 17, 20, 16, 41, 21, 38, 43, 31, 2};

    printf("\n Vetor inicial: \n");
    // for(posicao = 0; posicao < tam; posicao++){
    //     vetor[posicao] = rand()%100; 
    // }
    for (posicao = 0; posicao < tam; posicao++){
        printf("%d ", vetor[posicao]);
    }
    quicksort(vetor, 0, (tam - 1));
    printf("\n Vetor ordenado pelo quicksort: \n");
    for(posicao = 0; posicao < tam; posicao++){
        printf("%d ", vetor[posicao]);
    }
    printf("\n Digite o valor a ser pesquisado:\n ");
    scanf("%d", &resp);

    pos = buscaBinaria(vetor, resp, vetor[0], vetor[13]);
    if(pos < 0){
        printf("Valor %d não encontrado!\n", resp);
    }else{
        printf("O valor %d foi encontrado\n", resp);
    }



    return 1;
}


