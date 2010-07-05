/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "coral.h"

/*inicia corais de uma determinada fase do jogo*/
void inicia_corais(int fase, int oceano[][MAX_LONGITUDE]){
  switch (fase){
  case 1: 
    inicia_fase1(oceano);
    break;
    /*futura implementacao para mais de uma fase*/
  }
}

/* verifica se uma posicao esta fora do oceano */
int esta_dentro_do_oceano(int y, int x){
  if(x < 0 || x >= MAX_LONGITUDE ||
     y < 0 || y >= MAX_LATITUDE)
    return 0;
  return 1;
}

/* calcula a distancia quadratica entre o centro do coral e o ponto em analise */
int distancia_quadratica_entre_centro_do_coral_e_ponto(int y, int x, Coral coral){
  int distancia_x = x - coral.centro_x;
  int distancia_y = y - coral.centro_y;

  return (distancia_x*distancia_x) + (distancia_y*distancia_y);
}

/* verifica se o ponto em analise eh interno ao coral */
int esta_dentro_do_coral(int y, int x, int id){
  Coral coral = vetor_de_corais[id];
  if(distancia_quadratica_entre_centro_do_coral_e_ponto(y, x, coral) <= (RAIO_CORAL * RAIO_CORAL))
	return 1;
  return 0;
}

int esta_em_algum_coral(int y, int x){
  int i;
  for(i = 0; i < NUMERO_DE_CORAIS; i++)
	if(esta_dentro_do_coral(y, x, i))
	  return 1;
  return 0;
}

void coloca_coral_no_oceano(int id, int oceano[][MAX_LONGITUDE]){
  int x, y;
  int centro_x, centro_y;
  centro_x = vetor_de_corais[id].centro_x;
  centro_y = vetor_de_corais[id].centro_y;
  
  for(y = (centro_y - RAIO_CORAL); y <= (centro_y + RAIO_CORAL); y++)
	for(x = (centro_x - RAIO_CORAL); x <= (centro_x + RAIO_CORAL); x++)
	  if(esta_dentro_do_oceano(y, x) && esta_dentro_do_coral(y, x, id))
		oceano[y][x] = CORAL;
}

void cria_coral(int id, int coordenada_y, int coordenada_x, int oceano[][MAX_LONGITUDE]){
  vetor_de_corais[id].centro_y = coordenada_y;
  vetor_de_corais[id].centro_x = coordenada_x;
  coloca_coral_no_oceano(id, oceano);
}

/*desenha os corais da fase 1*/
void inicia_fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int quant_de_corais = 0;

  cria_coral(quant_de_corais++,    0,    0, oceano);
  cria_coral(quant_de_corais++,    0, 1024, oceano);
  cria_coral(quant_de_corais++,  768,    0, oceano);
  cria_coral(quant_de_corais++,  768, 1024, oceano);
}


void imprime_fase(int quant_corais){
  int i;
  for(i = 0; i < quant_corais; i++)
	desenha_coral(screen, vetor_de_corais[i].centro_y, vetor_de_corais[i].centro_x);
}

void escolhe_fase_para_imprimir(int fase){
 switch (fase){
  case 1: 
    imprime_fase(4);
    break;
  } 
}

