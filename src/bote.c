/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "bote.h"

void cria_bote(int id, int y, int x){
  botes[id].coordenada_y = y;
  botes[id].coordenada_x = x;
  botes[id].modulo_velocidade = VEL_BOTE;
  botes[id].tempo_no_lugar = 0;
  botes[id].direcao = 4 - id;
}

void cria_botes(){
  cria_bote(0, 760, 410);
  cria_bote(1, 760, 630);
}

void imprime_botes(BITMAP *destino){
  desenha_botes(destino, botes);
}
