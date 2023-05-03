#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vetor[], int size) {
    for (int i = 1; i < size; i++) {
        int key = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}

int main() {
    int vetor[20000];
    int size = sizeof(vetor) / sizeof(vetor[0]);

    for(int i = 0; i < size ; i++){
        vetor[i] = rand() ;
        // printf("vetor na posição %d = %d\n", i, vetor[i]);
    };

    // printf("vetor antes do Insertion Sort: ");
    for (int i = 0; i < size; i++) {
        // printf("%d \n", vetor[i]);
    }
    clock_t begin = clock();
    insertionSort(vetor, size);
    clock_t end = clock();
    // printf("vetor depois do Insertion Sort: ");
    for (int i = 0; i < size; i++) {
        // printf("%d \n", vetor[i]);
    }
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    
    return 0;
}
