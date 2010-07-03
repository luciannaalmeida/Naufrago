/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "bote.h"

Bote botes[2];

void cria_bote(int id, int y, int x){
  botes[id].coordenada_y = y;
  botes[id].coordenada_x = x;
  botes[id].modulo_velocidade = rand() % MAX_VEL_BOTE;
  botes[id].tempo_no_lugar = 0;
  botes[id].direcao = rand() % 8;
  botes[id].numero_de_resgates = 0;
}

void cria_botes(){
  cria_bote(0, 760, 410);
  cria_bote(1, 760, 630);
}

void imprime_botes(BITMAP *destino){
  desenha_botes(destino, botes);
}

int pega_y_da_base_do_bote(int id){
  return botes[id].coordenada_y;
}

int pega_x_da_base_do_bote(int id){
  return botes[id].coordenada_x;
}

int pega_direcao_do_bote(int id){
  return botes[id].direcao;
}

void seta_direcao_do_bote(int id, int nova_direcao){
  botes[id].direcao = nova_direcao;
}

void seta_y_da_base_do_bote(int id, int novo_y_da_base){
  botes[id].coordenada_y = novo_y_da_base;
}

void seta_x_da_base_do_bote(int id, int novo_x_da_base){
  botes[id].coordenada_x = novo_x_da_base;
}

void aumenta_numero_de_resgates(int id){
  (botes[id].numero_de_resgates)++;
}

Bote pega_bote(int id){
  return botes[id];
}

void troca_direcao_do_bote(int id, int direcao){
  botes[id].direcao = direcao;
}
