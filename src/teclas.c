/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/


#include "teclas.h"
int esquerda_bote_1 = 0, esquerda_bote_2 = 0;
int direita_bote_1 = 0, direita_bote_2 = 0;
int acelera_bote_1 = 0, desacelera_bote_1 = 0;
int acelera_bote_2 = 0, desacelera_bote_2 = 0;

int trata_click_direcional(int bote, int contador, int direcao, int *contador_direcao_contraria){
  contador++;
  *contador_direcao_contraria = 0;
  if(contador >= MINIMO_DE_CLICKS){
    atualiza_direcao(bote, direcao);    
    return 0;
  }
  return contador;
}

int trata_click_aceleracao(int bote, int contador, int *contador_direcao_contraria, int aceleracao){
  contador++;
  *contador_direcao_contraria = 0;
  if(contador >= MINIMO_DE_CLICKS){
    atualiza_velocidade(bote, aceleracao);    
    return 0;
  }
  return contador;
}

void trata_comandos_do_jogador(){
  int bote1 = 0;
  int bote2 = 1;
  /*MINIMO_DE_CLICKS eh o numero minimo de clicks que deve-se dar na tecla para ocorrer a mudanca de direcao*/

  if(key[KEY_UP])
    acelera_bote_2 = trata_click_aceleracao(bote2, acelera_bote_2, &desacelera_bote_2, 1);
  
  if(key[KEY_DOWN])
    desacelera_bote_2 = trata_click_aceleracao(bote2, desacelera_bote_2, &acelera_bote_2, -1);
  
  if(key[KEY_LEFT])
    esquerda_bote_2 = trata_click_direcional(bote2, esquerda_bote_2, 1, &direita_bote_2);
  
  if(key[KEY_RIGHT])
    direita_bote_2 = trata_click_direcional(bote2, direita_bote_2, -1, &esquerda_bote_2);
    
  if(key[KEY_RCONTROL])
    atualiza_ancora(bote2);  
  
  if(key[KEY_W])
    acelera_bote_1 = trata_click_aceleracao(bote1, acelera_bote_1, &desacelera_bote_1, 1);
  
  if(key[KEY_S])
    desacelera_bote_1 = trata_click_aceleracao(bote1, desacelera_bote_1, &acelera_bote_1, -1);
  
  if(key[KEY_A])
    esquerda_bote_1 = trata_click_direcional(bote1, esquerda_bote_1, 1, &direita_bote_1);

  if(key[KEY_D])
    direita_bote_1 = trata_click_direcional(bote1, direita_bote_1, -1, &esquerda_bote_1);
  
  if(key[KEY_Q])
    atualiza_ancora(bote1);
  
}
