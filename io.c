#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"

// Cria imagem a partir do vetor de altitudes do contorno (Adaptado de https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C)
void cria_imagem(int dimx, int dimy, char arquivo[], Pixel **imagem) {
    FILE *fp = fopen(arquivo, "wb");
    fprintf(fp, "P6\n%d\n%d\n255\n", dimx, dimy);

    for (int i = 0; i < dimy; i++)
        fwrite(imagem[i], sizeof(Pixel), dimx, fp);

    fclose(fp);
}
