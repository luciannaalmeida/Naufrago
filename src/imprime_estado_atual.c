/*
  EP2 - Laboratório de Programação     10/05/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "imprime_estado_atual.h"

/* Limpa o terminal para imprimir o oceano */
void clear_terminal(){
  printf("\033[2J\033[0;0f");
}

void imprime_no_modo_grafico(int fase, int oceano[][MAX_LONGITUDE]){
  int y,x;
  /* BITMAP * tela = desenha_oceano();  */
  clear_to_color( screen, makecol( 0, 0, 255));
  
  acquire_screen();

  escolhe_fase_para_imprimir(fase);

  imprime_asimov(screen);
  
  imprime_botes(screen);

  for(y = 0; y < MAX_LATITUDE; y++){
    for(x = 0; x < MAX_LONGITUDE; x++){
      if(oceano[y][x] == PASSAGEIRO)
		desenha_passageiro(screen, y, x);
      else if (oceano[y][x] > PASSAGEIRO)
		desenha_colisao(screen, y, x);
    }
  }
  release_screen();
  /* readkey(); */
}

/* Imprime o estado atual do oceano */
void imprime_oceano(int fase, int oceano[][MAX_LONGITUDE]){
  /* int i, j;  */
  /* clear_terminal(); */
  /* for(i = 0; i < MAX_LATITUDE; ++i){ */
  /*   for(j = 0; j < MAX_LONGITUDE; ++j){ */
  /* 	  /\* Imprime . onde eh agua *\/ */
  /*     if(oceano[i][j] == AGUA) */
  /* 		printf("."); */
  /* 	  /\* Imprime @ onde existe apenas um passageiro *\/ */
  /*     else if(oceano[i][j] == PASSAGEIRO) */
  /* 	  	printf("@"); */
  /* 	  /\* Imprime * onde ocorreu colisao *\/ */
  /* 	  else */
  /* 	  	printf("*"); */
  /*   } */
  /*   printf("\n"); */
  /* } */

  imprime_no_modo_grafico(fase, oceano);
}
