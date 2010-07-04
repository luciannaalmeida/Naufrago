/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "imprime_estado_atual.h"

/* Imprime o estado atual do oceano */
void imprime_oceano(int fase, int oceano[][MAX_LONGITUDE]){
  int y,x;
  clear_to_color( screen, makecol( 0, 0, 255));
  
  acquire_screen();

  escolhe_fase_para_imprimir(fase);

  imprime_asimov(screen);

  for(y = 0; y < MAX_LATITUDE; y++){
    for(x = 0; x < MAX_LONGITUDE; x++){
      if(oceano[y][x] == PASSAGEIRO)
		desenha_passageiro(screen, y, x);
      else if (oceano[y][x] > PASSAGEIRO)
		desenha_colisao(screen, y, x);
    }
  }

  imprime_botes(screen);
  imprime_informacoes(screen);

  release_screen();
}
