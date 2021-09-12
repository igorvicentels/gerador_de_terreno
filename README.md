# Gerador de terreno

Gerador de terreno é uma ferramenta que gera a imagem (em formato PPM) de um terreno com a utilização do método do deslocamento do ponto do meio

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
-o -d -s -c
```

* -o <arquivo>: nome do arquivo
* -d <num>: deslocamento máximo do ponto médio (quanto maior esse valor mais acidentado será o terreno)
* -s <num>X<num>: dimensões da imagem gerada
* -c <num>: número de camadas de terreno (entre 1 e 3)

#### Exemplo de uso

```cmd
./terrain -o terreno.ppm -d 100 -s 1000X500 -c 2
```
O comando acima gerará um arquivo de imagem nomeado "terreno.ppm", no formato 1000 x 500 (largura x altura), o deslocamento máximo inicial do ponto médio usado nos cálculos será 100 pixels e o programa gerará duas camadas de terreno.

Caso o usuário não utilize esses argumentos, o programa usará os seguintes valores padrão:

* nome: terreno.ppm
* dimensões da imagem: 1280 x 720
* deslocamento máximo: 10% da altura da imagem
* número de camadas: 1







Arquivos:
terrain.c -> função principal
io.c -> entrada e saida de dados
io.h -> assinatura das funções implementadas em io.c
funcs.c -> funções
funcs.h -> assinatura das funções usadas em funcs.c
difinitions.h -> definições de tipos

Falta:
Checar se os valores inseridos na linha de comando são adequados
Criar tipos
Verificar o que seria essa geração de gradientes (blur?)

Duvidas:
Como checar se os comando digitados na linha de comando são adequados?
P3 ou P6?

Autor:
Igor Vicente Lourenço Silva

