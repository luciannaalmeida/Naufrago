/*
  EP3 - Laboratório de Programação     9/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "estado_inicial.h"

/* Funcao que popula a matriz oceano com agua */
void coloca_agua_no_oceano(int oceano[][MAX_LONGITUDE]){
  int y, x;
  for(y = 0; y < MAX_LATITUDE; y++)
    for(x = 0; x < MAX_LONGITUDE; x++)
      oceano[y][x] = AGUA;
}

/* Funcao que gera as condicoes iniciais do oceano */
naufrago* gera_estado_inicial_oceano(int oceano[][MAX_LONGITUDE]){
  int i;
  /* Cria vetor de passageiros, com o valor da constante QTD_MAXIMA_PASSAGEIROS */
  naufrago *passageiros = malloc(QTD_MAXIMA_PASSAGEIROS * sizeof(struct naufrago));
  
  /* Chama funcao que popula o oceano com agua */
  coloca_agua_no_oceano(oceano);
  
  /* Gera todos os passageiros iniciais */
  for(i = 0; i < QTD_INICIAL_PASSAGEIROS; ++i )
    gera_e_coloca_passageiro_no_oceano(passageiros, i, oceano);

  return passageiros;
}

