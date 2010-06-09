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

/*desenha os corais da fase 1*/
void fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  vetor_posicao_dos_corais[0].x = 0;
  vetor_posicao_dos_corais[0].y = 384;
  oceano[384][0] = -1;
  desenha_coral(screen, 0, 384);

  vetor_posicao_dos_corais[1].x = 1024;
  vetor_posicao_dos_corais[1].y = 0;
  oceano[1024][0] = -1;
  desenha_coral(screen, 1024, 0);

  vetor_posicao_dos_corais[2].x = 1024;
  vetor_posicao_dos_corais[2].y = 768;
  oceano[1024][768] = -1;
  desenha_coral(screen, 1024, 768);
}
