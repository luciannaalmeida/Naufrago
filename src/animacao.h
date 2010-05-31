/*
  EP2 - Laboratório de Programação     10/05/2010

  Integrantes:
  Lucianna Thomaz Almeida      5893802
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/
#ifndef ANIMACAO_H
#define ANIMACAO_H

#include <allegro.h>
#include "constantes.h"

/* Valores padrão para inicialização do Allegro.*/
#define BITS_CORES_GRAFICO      8
#define RESOLUCAO_HORIZONTAL 1024
#define RESOLUCAO_VERTICAL     768
#define VIRTUAL_HORIZONTAL      0
#define VIRTUAL_VERTICAL        0

/* Opção para inicializar a animação com valores padrão. */
void inicializa_padrao();

/* Opção para inicializar a animação com valores definidos pelo usuário. */
void incicializa_animacao(int bits_cores_grafico, int resolucao_horizontal, int resolucao_vertical);

/* Carrega uma figura de um dado arquivo */
BITMAP *carrega_figura(char *nomeArquivo);

/* Insere uma figura origem em um local determinado de um destino*/
void sobrepoe_figuras(BITMAP *origem, BITMAP *destino, int x_inicial, int y_inicial, int altura, int largura);

/* Insere um bitmap na tela */
void insere_figura_tela(BITMAP *bitmap);

/* Desenha um círculo centrado nas coordenadas x e y.*/
void desenha_circulo(BITMAP *bitmap, int x, int y, int raio, int cor);

/* Desenha um retângulo entre as coordenadas x_inicial, x_final, y_inicial e y_final.*/
void desenha_retangulo(BITMAP *bitmap, int x_inicial, int y_inicial, int x_final, int y_final, int cor);

void salva_bitmap(char *filename, BITMAP *bmp);


void finaliza_animacao();

#endif
