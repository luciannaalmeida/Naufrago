/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "asimov.h"

int numero_total_de_resgates = 0;

/* verifica se posicao esta dentro da asimov */
int esta_na_asimov(int y, int x, int delta_de_aproximacao){
  int minimo_y, maximo_y, minimo_x, maximo_x;
  minimo_y = y1_ASIMOV - delta_de_aproximacao;
  maximo_y = y2_ASIMOV + delta_de_aproximacao;
  minimo_x = x1_ASIMOV - delta_de_aproximacao;
  maximo_x = x2_ASIMOV + delta_de_aproximacao;
  return (y >= minimo_y && y <= maximo_y && x >= minimo_x && x <= maximo_x);
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

void atualiza_numero_total_de_resgates(int quantidade){
  numero_total_de_resgates += quantidade;
}

int pega_quantidade_total_de_resgates(){
  return numero_total_de_resgates;
}
