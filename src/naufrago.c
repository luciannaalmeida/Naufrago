/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "naufrago.h"

int velocidade_maxima_passageiros = VEL_MAX_PASSAGEIROS;
int velocidade_minima_passageiros = VEL_MIN_PASSAGEIROS;
int velocidade_media_passageiros;

/* Seta velocidade_maxima_passageiros para os testes */
void seta_velocidade_maxima_passageiros(float velocidade_maxima){
  velocidade_maxima_passageiros = (int)(velocidade_maxima * 100);
}

/* Seta velocidade_minima_passageiros para os testes */
void seta_velocidade_minima_passageiros(float velocidade_minima){
  velocidade_minima_passageiros = (int)(velocidade_minima * 100);
}

/* Seta velocidade media e maxima dos passageiros para os testes e para parametros */
void seta_velocidade_media_passageiros(float velocidade_media){
  velocidade_media_passageiros  = (int)(velocidade_media * 100);
  if(velocidade_media_passageiros * 2 <= 100)
	velocidade_maxima_passageiros = velocidade_media_passageiros * 2; 
}

/* Funcao que gera aleatoriamente valores entre ? e ?, a partir de uma semente */
int gera_aleatorio(){
  return rand();
}

/* Gera velocidade aleatoria */
int gera_velocidade_passageiro_aleatoria(){
  if(velocidade_maxima_passageiros > 0){
	/* Para deixar a velocidade entre a minima e a maxima definidas, fazemos (max-min) para o modulo e somamos com (min + 1) */
  	return ((gera_aleatorio() % (velocidade_maxima_passageiros - velocidade_minima_passageiros + 1)) + velocidade_minima_passageiros);
  }
  return 1;
}

/* Gera direcao aleatoria */
int gera_direcao_aleatoria(){
  return (gera_aleatorio() % 8);
}

/* verifica se um passageiro esta fora do oceano */
int esta_fora_do_oceano(naufrago passageiro){
  if(passageiro.coordenada_x < 0 || passageiro.coordenada_x >= MAX_LONGITUDE ||
     passageiro.coordenada_y < 0 || passageiro.coordenada_y >= MAX_LATITUDE)
    return 1;
  return 0;
}

/* Gera posicao aleatoria para o passageiro */
naufrago gera_posicao_aleatoria(naufrago passageiro){
  passageiro.coordenada_x  = gera_aleatorio() % MAX_LONGITUDE;
  passageiro.coordenada_y = gera_aleatorio() % MAX_LATITUDE;
  return passageiro;
}

/* verifica se a posicao ja esta ocupada */
int posicao_ocupada(naufrago passageiro, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  if(oceano[passageiro.coordenada_y][passageiro.coordenada_x] == AGUA)
    return 0;
  return 1;
}

void coloca_passageiro_no_oceano(naufrago passageiro, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  oceano[passageiro.coordenada_y][passageiro.coordenada_x] += PASSAGEIRO;
}

/* Funcao que gera um passageiro, com uma posicao e uma velocidade aleatorios */
void gera_passageiro(naufrago *passageiros, int i, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){

  /* Salvar o id do passageiro */
  passageiros[i].id = i;
  
  /* Gerar vetor velocidade, entre a faixa de valores VEL_MIN e VEL_MAX */
  passageiros[i].modulo_velocidade = gera_velocidade_passageiro_aleatoria(); /*+ VEL_MIN;*/
  passageiros[i].direcao = gera_direcao_aleatoria();
  passageiros[i].houve_colisao = 0;
  passageiros[i].tempo_no_lugar = 0;

  /* Gerar as componentes do vetor posicao, entre a faixa de valores MAX_LATITUDE e MAX_LONGITUDE */
  passageiros[i] = gera_posicao_aleatoria(passageiros[i]);
  while(posicao_ocupada(passageiros[i], oceano))
    passageiros[i] = gera_posicao_aleatoria(passageiros[i]);
}

/* gera passageiro em qualquer lugar do oceano. Essa geracao eh usada para inicializar do jogo */
void gera_e_coloca_passageiro_no_oceano(naufrago *passageiros, int id, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  gera_passageiro(passageiros, id, oceano);
  coloca_passageiro_no_oceano(passageiros[id], oceano);
}

/* Verifica se passageiro nao esta na borda da matriz oceano */
int nao_esta_na_borda(naufrago passageiro){
  /* verifica se passageiro esta na borda do oceano */
  if(passageiro.coordenada_x != 0 && passageiro.coordenada_x != (MAX_LONGITUDE - 1) &&
     passageiro.coordenada_y != 0 && passageiro.coordenada_y != (MAX_LATITUDE -1))
	return 1;
  return 0;
}

/* Reinicializa passageiro para que ele seja recriado em uma das bordas */
naufrago reinicializa_passageiro(naufrago passageiro){
  passageiro.modulo_velocidade = gera_velocidade_passageiro_aleatoria();
  while(nao_esta_na_borda(passageiro))
	passageiro = gera_posicao_aleatoria(passageiro);
  passageiro.direcao = gera_direcao_aleatoria();
  return passageiro;
}

void gera_passageiro_na_borda(naufrago *passageiros, int id, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  gera_passageiro(passageiros, id, oceano);
  while(nao_esta_na_borda(passageiros[id]))
	passageiros[id] = gera_posicao_aleatoria(passageiros[id]);
  coloca_passageiro_no_oceano(passageiros[id], oceano);
}
