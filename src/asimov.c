/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "asimov.h"

/* verifica se posicao esta dentro da asimov */
int esta_na_asimov(int y, int x){
  return (y >= y1_ASIMOV && y <= y2_ASIMOV && x >= x1_ASIMOV && x <= x2_ASIMOV);
} 

/* verifica se uma posicao esta fora do oceano */
int ponto_dentro_do_oceano(int y, int x){
  if(x < 0 || x >= MAX_LONGITUDE ||
     y < 0 || y >= MAX_LATITUDE)
    return 0;
  return 1;
}

void cria_asimov(int oceano[][MAX_LONGITUDE]){
  int x, y;
  for(y = y1_ASIMOV; y < y2_ASIMOV; y++)
	for(x = x1_ASIMOV; x < x2_ASIMOV; x++)
	  if(ponto_dentro_do_oceano(y, x))
		oceano[y][x] = ASIMOV;
}

void imprime_asimov(BITMAP *destino){
  desenha_asimov(destino, y1_ASIMOV, x1_ASIMOV, y2_ASIMOV, x2_ASIMOV);
}

