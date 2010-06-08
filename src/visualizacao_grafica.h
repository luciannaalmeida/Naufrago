#ifndef VISUALIZACAO_GRAFICA_H
#define VISUALIZACAO_GRAFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "constantes.h"



void inicializa_janela_padrao();
void incicializa_janela(int resolucao_horizontal, int resolucao_vertical);
BITMAP * carrega_imagem(char *nomeArquivo);
void insere_imagem_na_tela(BITMAP *bitmap, int x, int y);
BITMAP* desenha_oceano();
void desenha_passageiro(BITMAP *destino, int x, int y);
void desenha_colisao(BITMAP *destino, int x, int y);
void desenha_coral(BITMAP *destino, int x, int y);

#endif
