#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"

// Função que gera o vetor do contorno a partir do algoritmo de deslocamento do ponto do meio
void gera_contorno (int* vetor, int i, int f, int max_var) {
  if (i + 1 < f) {
    int meio = (i + f) / 2;
    vetor[meio] = ((vetor[i] + vetor[f]) / 2) + (rand() % (1 + (2 * max_var)) - max_var);
    gera_contorno(vetor, i, meio, (int) (max_var * 0.55));
    gera_contorno(vetor, meio, f, (int) (max_var * 0.55));
  }
}

void inicializa_bitmap(int dimx, int dimy, Pixel** imagem) {
  for (int i = 0; i < dimy; i++) {
    for (int j = 0; j < dimx; j++) {
      imagem[i][j].red = 135;
      imagem[i][j].green = 206;
      imagem[i][j].blue = 235; 
    }
  }
}

void gera_bitmap(int dimx, int dimy, int* vetor, Pixel** imagem, int k) {
  int red;
  int green;
  int blue;

  switch (k) {
    case 0:  red = 34; green = 139; blue = 34; break;
    case 1: red = 107; green = 142; blue = 35; break;
    case 2: red = 0; green = 0; blue = 0; break;
  }
  for (int i = 0; i < dimy; i++) {
    for (int j = 0; j < dimx; j++) {
      if (dimy - i <= vetor[j]) {
        imagem[i][j].red = red;
        imagem[i][j].green = green;
        imagem[i][j].blue = blue;
      } 
    }
  }
}

