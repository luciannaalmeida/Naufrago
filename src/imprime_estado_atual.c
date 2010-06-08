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

void imprime_no_modo_grafico(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int i,j;
   /* BITMAP * tela = desenha_oceano();  */
   clear_to_color( screen, makecol( 0, 0, 255));

     acquire_screen();

  for(i = 0; i < MAX_LATITUDE; ++i){
    for(j = 0; j < MAX_LONGITUDE; ++j){
      if(oceano[i][j] == PASSAGEIRO)
	desenha_passageiro(screen, i, j);
      else if (oceano[i][j] != AGUA)
	desenha_colisao(screen, i, j);
    }
  }
  release_screen();
  /* readkey(); */
}

/* Imprime o estado atual do oceano */
void imprime_oceano(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int i, j; 
  clear_terminal();
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

  imprime_no_modo_grafico(oceano);
}
