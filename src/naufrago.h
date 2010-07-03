/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef NAUFRAGO_H
#define NAUFRAGO_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct naufrago {
  int id;
  int coordenada_x, coordenada_y;
  int modulo_velocidade;
  int tempo_no_lugar;
  int direcao;
  int houve_colisao;
}naufrago;

#include "jogo.h"

int esta_no_passageiro(int y, int x, naufrago passageiro);
void seta_velocidade_maxima_passageiros(float velocidade_maxima);
void seta_velocidade_minima_passageiros(float velocidade_minima);
void seta_velocidade_media_passageiros(float velocidade_media);
int esta_fora_do_oceano(naufrago passageiro);
void gera_passageiro(naufrago *passageiros, int posicao, int oceano[MAX_LATITUDE][MAX_LONGITUDE]);
void gera_e_coloca_passageiro_no_oceano(naufrago *passageiros, int posicao, int oceano[MAX_LATITUDE][MAX_LONGITUDE]);
int gera_velocidade_passageiro_aleatoria();
naufrago reinicializa_passageiro(naufrago passageiro);

#endif
