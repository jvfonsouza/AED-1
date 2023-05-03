#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}

int main() {
    int vetor[20000];
    int size = sizeof(vetor) / sizeof(vetor[0]);

    for(int i = 0; i < size ; i++){
        vetor[i] = rand();
        // printf("vetor na posição %d = %d\n", i, vetor[i]);
    };

    // printf("vetor antes do Selection Sort:");
    for (int i = 0; i < size; i++) {
        // printf("%d\n ", vetor[i]);
    }
    clock_t begin = clock();
    selectionSort(vetor, size);
    clock_t end = clock();
    // printf("vetor depois do Selection Sort:");
    for (int i = 0; i < size; i++) {
        // printf("%d\n ", vetor[i]);
    }
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    
    return 0;
}
