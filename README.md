# Gerador de terreno

Gerador de terreno é uma ferramenta que gera a imagem (em formato PPM) de um terreno com a utilização do método do deslocamento do ponto do meio

## O que foi feito

O programa gera a imagem de um terreno de acordo com parâmetros inseridos pelo usuário na linha de comando. Esses Parâmetros são os seguintes: 

* Nome do arquivo de imagem (PPM) a ser criado
* Deslocamento máximo do ponto médio
* Dimensões da imagem a ser gerada
* Número de camadas de terreno
* Esquema de cores a ser utilizado na imagem

## O que seria feito diferente

Inicialmente, a ideia era deixar o usuário escolher as cores do céu e de cada camada de terreno individualmente, porém, para o uso do programa não ficar muito confuso, foi decidido criar dois esquemas de cores e deixar o usuário escolher um deles.

## Compilação do projeto

#### Windows
```cmd
mingw32-make all
```
#### Linux
```cmd
make all
```

## Uso

```cmd
./terrain
```

#### Flags 

```cmd
-o -d -s -c -n
```

* -o <arquivo>: nome do arquivo
* -d <num>: deslocamento máximo do ponto médio (quanto maior esse valor mais acidentado será o terreno)
* -s <num>X<num>: dimensões da imagem gerada
* -c <num>: número de camadas de terreno (entre 1 e 3)
* -n: altera esquema de cores de "dia" para "noite"

#### Exemplo de uso

```cmd
./terrain -o terreno.ppm -d 100 -s 1000X500 -c 2 -n
```
O comando acima gerará um arquivo de imagem nomeado "terreno.ppm", no formato 1000 x 500 (largura x altura), o deslocamento máximo inicial do ponto médio usado nos cálculos será 100 pixels, o programa gerará duas camadas de terreno e o esquema de cores utilizado será: noite.

Caso o usuário não utilize esses argumentos, o programa usará os seguintes valores padrão:

* nome: terreno.ppm
* dimensões da imagem: 1280 x 720
* deslocamento máximo: 10% da altura da imagem
* número de camadas: 3
* esquema de cores: dia



## Autor

Igor Vicente Lourenço Silva

