#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separa(int vetor[], int start, int end) {
   int c = vetor[end];
   int t = 0, j = start;
   for (int i = start; i < end; ++i)
      if (vetor[i] <= c) {
         t = vetor[j], vetor[j] = vetor[i], vetor[i] = t;
         ++j; 
      } 
   t = vetor[j], vetor[j] = vetor[end], vetor[end] = t;
   return j; 
}

void quicksort (int vetor[], int start, int end)
{
   if (start < end) {                   
      int pivo = separa (vetor, start, end);   
      quicksort (vetor, start, pivo-1);      
      quicksort (vetor, pivo+1, end);     
   }
  
}

int main(){
    int vetor[20000];
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    // printf("tamanho: %d", tamanhoVetor);

    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = rand() ;
        // printf("vetor na posição %d = %d\n", i, vetor[i]);
    };

    
    clock_t begin = clock();
    quicksort(vetor, 0, tamanhoVetor - 1);
    clock_t end = clock();
    
    for(int i = 0; i < 50; i++){
        // printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);

	return 0; 
}
