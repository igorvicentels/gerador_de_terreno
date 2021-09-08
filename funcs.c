#include <stdlib.h>
#include <stdio.h>

// Função que gera o vetor com a altura de cada barra a partir do algoritmo de deslocamento do ponto do meio
void gera_terreno (int vetor[], int i, int f, int max_var) {
  if (i + 1 < f) {
    int meio = (i + f) / 2;
    vetor[meio] = (vetor[i] + vetor[f]) / 2 + (rand() % (1 + (2 * max_var)) - max_var);
    gera_terreno(vetor, i, meio, max_var);
    gera_terreno(vetor, meio, f, max_var);
  }
}

void blur (char arquivo[]) {
  
}