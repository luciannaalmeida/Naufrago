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

/* verifica se uma posicao esta fora do oceano */
int esta_dentro_do_oceano(int x, int y){
  if(x < 0 || x >= MAX_LONGITUDE ||
     y < 0 || y >= MAX_LATITUDE)
    return 0;
  return 1;
}

void coloca_coral_no_oceano(int id, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  /* int x, y, cont; */
  /* int centro_x, centro_y; */
  /* centro_x = vetor_de_corais[id].centro_x; */
  /* centro_y = vetor_de_corais[id].centro_y; */

  /* /\* marca a parte superio do coral com a constante CORAL no oceano *\/ */
  /* for(cont = 0, y = (centro_y - RAIO_CORAL); y <= centro_y; y++, cont++){ */
  /* 	for(x = (centro_x - cont); x <= (centro_x + cont); x++){ */
  /* 	  if(esta_dentro_do_oceano(x, y)){ */
  /* 		oceano[y][x] = CORAL; */
  /* 	  } */
  /* 	} */
  /* } */
  /* /\* marca a parte inferior do coral com a constante CORAL no oceano *\/ */
  /* for(cont = 0, y = (centro_y + RAIO_CORAL); y > centro_y; y--, cont++){ */
  /* 	for(x = (centro_x - cont); x <= (centro_x + cont); x++){ */
  /* 	  if(esta_dentro_do_oceano(x, y)) */
  /* 		oceano[y][x] = CORAL; */
  /* 	} */
  /* } */
}

void cria_coral(int id, int coordenada_y, int coordenada_x, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  vetor_de_corais[id].centro_y = coordenada_y;
  vetor_de_corais[id].centro_x = coordenada_x;
  coloca_coral_no_oceano(id, oceano);
  desenha_coral(screen, coordenada_y, coordenada_x);
}

/*desenha os corais da fase 1*/
void fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int quant_de_corais = 0;

  cria_coral(quant_de_corais++,    0,    0, oceano);
  cria_coral(quant_de_corais++,    0, 1024, oceano);
  cria_coral(quant_de_corais++,  768,    0, oceano);
  cria_coral(quant_de_corais++,  768, 1024, oceano);
  /* cria_coral(quant_de_corais++,    0, 384, oceano); */
  /* cria_coral(quant_de_corais++,  1024,  0, oceano); */
  /* cria_coral(quant_de_corais++, 1024, 768, oceano); */
}
