#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"

// Cria imagem a partir do vetor de altitudes do contorno (Adaptado de https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C)
void cria_imagem(int dimx, int dimy, int* vetor, char arquivo[]) {
    FILE *fp = fopen(arquivo, "wb");
    fprintf(fp, "P6\n%d\n%d\n255\n", dimx, dimy);
    
    BITMAPPIXELS (*image)[dimx] = calloc(dimy, dimx * sizeof(BITMAPPIXELS));

    for (int i = 0; i < dimy; i++) {
        for (int j = 0; j < dimx; j++) {
            if (dimy - i <= vetor[j]) {
                image[i][j].red = 34;
                image[i][j].green = 139;
                image[i][j].blue = 34;
            } else {
                image[i][j].red = 135;
                image[i][j].green = 206;
                image[i][j].blue = 235; 
            }
        }
        fwrite(image[i], sizeof(BITMAPPIXELS), dimx, fp);
    }
    (void) fclose(fp);
}

