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
  botes[id].modulo_velocidade = 0;
  botes[id].tempo_no_lugar = 0;
  botes[id].direcao = 1;
  botes[id].numero_de_resgates = 0;
  botes[id].ancorado = 0;
  botes[id].pontos = 0;
  botes[id].vidas = NUMERO_INICIAL_DE_VIDAS;
  botes[id].bonus_de_vida = 0;
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


int pega_numero_de_vidas_do_bote(int id){
  return botes[id].vidas;
}

int pega_pontuacao_do_bote(int id){
  return botes[id].pontos;
}

int pega_velocidade_do_bote(int id){
  return botes[id].modulo_velocidade;
}

int pega_numero_de_passageiros_a_bordo(int id){
  return botes[id].numero_de_resgates;
}

int bote_lotado(int id){
  if(botes[id].numero_de_resgates >= LOTACAO_DO_BOTE)
    return 1;
  return 0;
}

int bote_ancorado(int id){
  return botes[id].ancorado;
}


int bote_afundou(int id){
  return (botes[id].vidas < 0);
}

int botes_afundaram(){
  return (bote_afundou(0) && bote_afundou(1));
}

Bote pega_bote(int id){
  return botes[id];
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

void troca_direcao_do_bote(int id, int direcao){
  botes[id].direcao = direcao;
}

int calcula_bonus_de_vida(int id, int aumento_de_pontuacao){
  botes[id].bonus_de_vida += aumento_de_pontuacao;
  if(botes[id].bonus_de_vida >= PONTUACAO_PARA_GANHAR_VIDA){
    botes[id].bonus_de_vida -= PONTUACAO_PARA_GANHAR_VIDA;
    return 1;
  }
  return 0;
}

void aumenta_numero_de_resgates(int id){
  int aumento_de_pontuacao = PONTUACAO_DE_RESGATE;
  (botes[id].numero_de_resgates)++;
  /* atualiza numero de vidas do bote */
  botes[id].vidas += calcula_bonus_de_vida(id,  aumento_de_pontuacao);
  botes[id].pontos += aumento_de_pontuacao;
}

void descarrega_passageiros(int id){
  int aumento_de_pontuacao = PONTUACAO_DE_DESCARREGO * (botes[id].numero_de_resgates);
  botes[id].pontos += aumento_de_pontuacao;
  /* atualiza numero de vidas do bote */
  botes[id].vidas += calcula_bonus_de_vida(id,  aumento_de_pontuacao);
  botes[id].numero_de_resgates = 0;
}

void atualiza_direcao(int id, int variacao){
  variacao %= 8; 
  if(botes[id].direcao + variacao < 0)
    variacao = 8 + variacao;
  botes[id].direcao = (botes[id].direcao + variacao)%8;
}

void atualiza_velocidade(int id, int variacao){
  int velocidade_nova = botes[id].modulo_velocidade + variacao;
  if(velocidade_nova >= 0 && velocidade_nova <= MAX_VEL_BOTE && !botes[id].ancorado)
    botes[id].modulo_velocidade += variacao;
}

void atualiza_ancora(int id){
  botes[id].ancorado = (botes[id].ancorado + 1)%2;
  botes[id].modulo_velocidade = 0;
}

void bote_perde_uma_vida(int id){
  botes[id].vidas--;
}

void zera_numero_de_resgates_do_bote(int id){
  botes[id].numero_de_resgates = 0;
}

