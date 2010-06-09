/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "coral.h"

/*inicia corais de uma determinada fase do jogo*/
void inicia_corais(int fase, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  switch (fase){
  case 1: 
    fase1(oceano);
    break;
    /*futura implementacao para mais de uma fase*/
  }
}

void coloca_coral_no_oceano(int id, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
}

void cria_coral(int id, int coordenada_x, int coordenada_y, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  vetor_de_corais[id].centro_x = coordenada_x;
  vetor_de_corais[id].centro_y = coordenada_y;
  coloca_coral_no_oceano(id, oceano);
  desenha_coral(screen, coordenada_x, coordenada_y);
}

/*desenha os corais da fase 1*/
void fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int quant_de_corais = 0;

  cria_coral(quant_de_corais++,    0, 384, oceano);
  cria_coral(quant_de_corais++,  1024,  0, oceano);
  cria_coral(quant_de_corais++, 1024, 768, oceano);
}
