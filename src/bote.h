/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef BARCOS_H
#define BARCOS_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct bote {
  int coordenada_x, coordenada_y;
  int modulo_velocidade;
  int tempo_no_lugar;
  int direcao;
  int numero_de_resgates;
}Bote;

#include "visualizacao_grafica.h"

void cria_botes();

void imprime_botes(BITMAP *destino);

/* funcoes de acesso as informacoes do bote */
int pega_y_da_base_do_bote(int id);
int pega_x_da_base_do_bote(int id);
int pega_direcao_do_bote(int id);

/* funcoes de atualizacoes das informacoes do bote*/
void seta_direcao_do_bote(int id, int nova_direcao);
void seta_y_da_base_do_bote(int id, int novo_y_da_base);
void seta_x_da_base_do_bote(int id, int novo_x_da_base);
void aumenta_numero_de_resgates(int id);
Bote pega_bote(int id);
void troca_direcao_do_bote(int id, int direcao);

#endif
