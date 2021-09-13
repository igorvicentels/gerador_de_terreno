#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "definitions.h"

// Função que gera o vetor do contorno a partir do algoritmo de deslocamento do ponto do meio
void gera_contorno(int *vetor, int i, int f, int max_var) {
	if (i + 1 < f) {
		int meio = (i + f) / 2;
		vetor[meio] = ((vetor[i] + vetor[f]) / 2) + (rand() % (1 + (2 * max_var)) - max_var);
		gera_contorno(vetor, i, meio, (int)(max_var * 0.55));
		gera_contorno(vetor, meio, f, (int)(max_var * 0.55));
	}
}

// Atribui a cor definida para o céu para todos os pixels
void inicializa_bitmap(int dimx, int dimy, Pixel **imagem, char cores[]) {
	int red, green, blue;
	// Verifica qual esquema de cores deve ser utilizado
	if (strcmp(cores, "dia") == 0) {
		red = 135;
		green = 206;
		blue = 235;
	}
	else {
		red = 12;
		green = 20;
		blue = 69;
	}
	// Preenche a matriz com os valores das cores de cada pixel
	for (int i = 0; i < dimy; i++) {
		for (int j = 0; j < dimx; j++) {
			imagem[i][j].red = red;
			imagem[i][j].green = green;
			imagem[i][j].blue = blue;
		}
	}
}

// Modifica a matriz de pixels a partir do vetor de contorno
void gera_bitmap(int dimx, int dimy, int *vetor, Pixel **imagem, int k, char cores[]) {
	int red;
	int green;
	int blue;

	// Definine os valores de vermelho, verde e azul da camada de acordo com o esquema de cores escolhido
	if (strcmp(cores, "dia") == 0) {
		switch (k) {
			case 0: red = 46; green = 139; blue = 87; break;
			case 1: red = 0; green = 110; blue = 0; break;
			case 2: red = 31; green = 61; blue = 12; break;
		}
	}
	else {
		switch (k) {
			case 0: red = 60; green = 82; blue = 120; break;
			case 1: red = 29; green = 41; blue = 81; break;
			case 2: red = 0; green = 10; blue = 20; break;
		}
	}
	// Modifica os valores das cores dos pixels pertencentes à camada 
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

// Instrui o usuário à respeito do modo de usar o programa
void usage() {
	printf("Instrucoes do programa:\n");
	printf("-d: indica a deslocamento maximo para o ponto do meio do vetor de contorno\n");
	printf("-o: indica o nome do arquivo de imagem a ser gerrado (deve terminar com .ppm)\n");
	printf("-s: indica as dimensoes da imagem (larguraXaltura)\n");
	printf("-c: indica o numero de camadas de terreno a ser gerada (entre 1 e 3)\n");
	printf("-n: indica que o padrão de cores deve ser alterado de dia para noite");
	printf("Ex.: ./terrain -d 100 -o terreno.ppm -s 1500X500 -c 2 -n\n");
}
