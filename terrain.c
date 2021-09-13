#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "funcs.h"
#include "io.h"
#include "definitions.h"

int main(int argc, char *argv[]) {
	int *vetor;						// Vetor para armazenar o contorno do terreno
	char arquivo[64];				// Variável com o nome do arquivo de imagem a ser gerado
	int dimx = 1280;				// Lagura da imagem
	int dimy = 720;					// Altura da imagem
	int max_var = (int)dimy * 0.20; // Variavel com a variação maxima da altitude
	int max_alt;					// Altitude máxima para as extremidades
	int min_alt;					// Altitude mínima para as extremidades
	int sent = 0;					// Variável para checar se o usuário escolheu uma max_var diferente do valor padrão
	int camadas = 3;				// Número de camadas de terreno gerados
	Pixel **imagem;					// Matriz que armazena os valores de vermelho, verde e azul de cada pixel
	char cores[6];                  // Variável que indica se o esquema de cores deve ser noite ou dia

	// Atribui um nome padrão para a imagem a ser gerada
	sprintf(arquivo, "%s", "terreno.ppm");

	// Configura o esquema de cores "dia" por padrão
	strcpy(cores, "dia");

	/*Lê os parametros de entrada da linha de comando 
	(veriação da altitude, nome do arquivo gerado, número de camadas, dimensões da imagem e esquema de cores)*/
	for (int i = 0; i < argc; i++) {
		// Lê valor do deslocamento aleatório máximo do ponto medio e verifica se o valor inserido é valido
		if (strcmp(argv[i], "-d") == 0) {
			if (atoi(argv[i + 1])) {
				max_var = atoi(argv[i + 1]);
				sent = 1;
				i++;
			}
			else {
				usage();
				exit(-1);
			}
		}
		// Lê nome do arquivo de imagem a ser gerado e verifica se o valor inserido é valido
		if (strcmp(argv[i], "-o") == 0) {
			sprintf(arquivo, "%s", argv[i + 1]);
			i++;
		}
		// Lê número de camadas de cadeias de montanhas a ser geradas e verifica se o valor insrrido é valido
		if (strcmp(argv[i], "-c") == 0) {
			if (atoi(argv[i + 1]) >= 1 && atoi(argv[i + 1]) <= 3) {
				camadas = atoi(argv[i + 1]);
				i++;
			}
			else {
				usage();
				exit(-1);
			}
		}
		// Lê dimensões do arquivo de imagem as ser gerado e verifica se o valor inserido é valido
		if (strcmp(argv[i], "-s") == 0) {
			if (sscanf(argv[i + 1], "%dX%d", &dimx, &dimy) == 2) {
				i++;
				if (sent == 0) {
					max_var = (int)(dimy * 0.2);
				}
			}
			else {
				usage();
				exit(-1);
			}
		}
		// Verifica se o esquema de cores deve ser alterado de "dia" para "noite"
		if (strcmp(argv[i], "-n") == 0) {
			strcpy(cores, "noite");
		}
	}

	vetor = malloc(sizeof(int) * dimx);

	// Gera o seed
	srand(time(NULL));

	// Alocação dinamica da matriz que armazena os valores de vermelho verde e azul de cada pixel
	imagem = malloc(sizeof(Pixel *) * dimy);
	for (int i = 0; i < dimy; i++)
		imagem[i] = malloc(sizeof(Pixel) * dimx);

	inicializa_bitmap(dimx, dimy, imagem, cores);

	for (int k = 0; k < camadas; k++) {
		// Define altitudes nas extremidades aleatóriamente
		max_alt = (int)(dimy * pow(0.7, k + 1));
		min_alt = (int)(dimy * (0.4 - 0.1 * k));
		do {
			vetor[0] = rand() % max_alt;
		} while (vetor[0] < min_alt);
		do {
			vetor[dimx - 1] = rand() % max_alt;
		} while (vetor[dimx - 1] < min_alt);

		// Calcula os valores do vetor de contorno
		gera_contorno(vetor, 0, dimx - 1, max_var);

		// Preenche a matriz de acordo com o vetor de contorno
		gera_bitmap(dimx, dimy, vetor, imagem, k, cores);
	}

	// Gera arquivo de imagem
	cria_imagem(dimx, dimy, arquivo, imagem);

	return 0;
}
