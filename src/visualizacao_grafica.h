#ifndef VISUALIZACAO_GRAFICA_H
#define VISUALIZACAO_GRAFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

/* Valores padrão para inicialização do Allegro.*/
#define RESOLUCAO_HORIZONTAL 1024
#define RESOLUCAO_VERTICAL    768
#define VIRTUAL_HORIZONTAL      0
#define VIRTUAL_VERTICAL        0

void inicializa_janela_padrao();
void incicializa_janela(int resolucao_horizontal, int resolucao_vertical);
BITMAP * carrega_imagem(char *nomeArquivo);
void insere_imagem_na_tela(BITMAP *bitmap, int x, int y);
void desenha_oceano();

#endif
