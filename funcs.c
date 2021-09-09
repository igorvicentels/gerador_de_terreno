#include <stdlib.h>
#include <stdio.h>

// Função que gera o vetor do contorno a partir do algoritmo de deslocamento do ponto do meio
void gera_terreno (int* vetor, int i, int f, int max_var) {
  if (i + 1 < f) {
    int meio = (i + f) / 2;
    vetor[meio] = ((vetor[i] + vetor[f]) / 2) + (rand() % (1 + (2 * max_var)) - max_var);
    gera_terreno(vetor, i, meio, (int) (max_var * 0.55));
    gera_terreno(vetor, meio, f, (int) (max_var * 0.55));
  }
}
