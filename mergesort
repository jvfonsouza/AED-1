#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            vetor[k++] = left[i++];
        } else {
            vetor[k++] = right[j++];
        }
    }
    while (i < left_size) {
        vetor[k++] = left[i++];
    }
    while (j < right_size) {
        vetor[k++] = right[j++];
    }
}

void mergeSort(int vetor[], int size) {
    if (size < 2) {
        return;
    }
    int mid = size / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));
    for (int i = 0; i < mid; i++) {
        left[i] = vetor[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = vetor[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(vetor, left, mid, right, size - mid);
    free(left);
    free(right);
}

int main() {
    int vetor[20000];
    int size = sizeof(vetor) / sizeof(vetor[0]);

    
    
    for(int i = 0; i < size; i++){
        vetor[i] = rand();
        // printf("vetor na posição %d = %d\n", i, vetor[i]);
    };
    
    for (int i = 0; i < size; i++) {
        // printf("%d ", vetor[i]);
    }
    clock_t begin = clock();
    mergeSort(vetor, size);
    clock_t end = clock();
    // printf("\nvetor depois do MergeSort:\n");
    for (int i = 0; i < size; i++) {
        // printf("%d ", vetor[i]);
    }

    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}
