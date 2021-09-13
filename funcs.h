#include "definitions.h"

void gera_contorno(int* vetor, int i, int f, int max_var);
void inicializa_bitmap(int dimx, int dimy, Pixel** imagem, char cores[]);
void gera_bitmap(int dimx, int dimy, int* vetor, Pixel* imagem[], int k, char cores[]);
void usage();