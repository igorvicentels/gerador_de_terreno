#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"

// Cria imagem a partir do vetor de altitude do contorno (Adaptado de https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C)
void cria_imagem(int dimx, int dimy, int vetor[], char arquivo[]) {
    FILE *fp = fopen(arquivo, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);
    
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

/* 
    // teste blur
    int red, green, blue;
    for (int i = 1; i < dimy - 1; i++) {
        for (int j = 1; j < dimx - 1; j++) {
            red = (image[i-1][j-1].red + image[i-1][j].red + image[i-1][j+1].red + image[i][j-1].red + red + image[i][j+1].red + image[i+1][j-1].red + image[i+1][j].red + image[i+1][j+1].red) / 9;
            green = (image[i-1][j-1].green + image[i-1][j].green + image[i-1][j+1].green + image[i][j-1].green + image[i][j].green + image[i][j+1].green + image[i+1][j-1].green + image[i+1][j].green + image[i+1][j+1].green) / 9;
            blue = (image[i-1][j-1].blue + image[i-1][j].blue + image[i-1][j+1].blue + image[i][j-1].blue + image[i][j].blue + image[i][j+1].blue + image[i+1][j-1].blue + image[i+1][j].blue + image[i+1][j+1].blue) / 9;
            image[i][j].red = red;
            image[i][j].green = green;
            image[i][j].blue = blue;
        }
    }

    for (int i = 0; i < dimx; i++) {
        fwrite(image[i], sizeof(BITMAPPIXELS), dimx, fp);
    }
 */

    (void) fclose(fp);
}

