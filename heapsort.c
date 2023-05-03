#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heap(int vetor[], int tamanho, int i) {
    int maior = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < tamanho && vetor[l] > vetor[maior])
        maior = l;

    if (r < tamanho && vetor[r] > vetor[maior])
        maior = r;

    if (maior != i) {
        int cont = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = cont;

        heap(vetor, tamanho, maior);
    }
}

void heapSort(int vetor[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heap(vetor, tamanho, i);

    for (int i = tamanho - 1; i >= 0; i--) {
        int cont = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = cont;

        heap(vetor, i, 0);
    }
}

int main() {
    int vetor[20000];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 20000;
        // printf("vetor na posição %d = %d\n", i, vetor[i]);
    };

    // printf("vetor antes do heap sort: ");
    

    clock_t begin = clock();
    heapSort(vetor, tamanho);
    clock_t end = clock();

    // printf("vetor depois do heap sort: ");
    

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);

    return 0;
}
