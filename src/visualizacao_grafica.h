/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/


#ifndef VISUALIZACAO_GRAFICA_H
#define VISUALIZACAO_GRAFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "constantes.h"
#include "bote.h"



void inicializa_janela_padrao();
void incicializa_janela(int resolucao_horizontal, int resolucao_vertical);
BITMAP * carrega_imagem(char *nomeArquivo);
void insere_imagem_na_tela(BITMAP *bitmap, int x, int y);
BITMAP* desenha_oceano();
void desenha_passageiro(BITMAP *destino, int x, int y);
void desenha_colisao(BITMAP *destino, int x, int y);
void desenha_coral(BITMAP *destino, int x, int y);
void desenha_asimov(BITMAP *destino, int y1, int x1, int y2, int x2);
void desenha_botes(BITMAP *destino, Bote botes[]);

#endif
