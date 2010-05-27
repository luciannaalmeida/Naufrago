/*
  EP2 - Laboratório de Programação     10/05/2010

  Integrantes:
  Lucianna Thomaz Almeida      5893802
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/
#ifndef GERA_ANIMACAO_H
#define GERA_ANIMACAO_H

#include "animacao.h"
#include <allegro.h>

/*TODO Verificar valores correspondentes às cores*/
#define AZUL     makecol(0, 191, 255)
#define SALMAO   makecol(255, 228, 196)
#define CORAL    makecol(255, 127, 80)
#define BEGE    makecol(222, 184, 135)
/*TODO Definir valores corretos para o tamanho do bote*/
#define LARGURA_BOTE 10
#define ALTURA_BOTE   5
/*TODO Definir valor correto para o tamanho do passageiro*/
#define RAIO_PASSAGEIRO 1

void gera_bitmap(int oceano[MAX_LATITUDE][MAX_LONGITUDE]);

/* Função que cria as figuras estáticas.*/
void cria_figuras();

/* Função que desenha os recifes aleatoriamente. */
void desenha_recife(BITMAP *recifes, int largura, int altura, int cor);

#endif