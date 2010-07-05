/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef BARCOS_H
#define BARCOS_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct bote {
  int coordenada_x, coordenada_y;
  int modulo_velocidade;
  int tempo_no_lugar;
  int direcao;
  int numero_de_resgates;
  int ancorado;
  int pontos;
  int vidas;
  int bonus_de_vida;
  char* jogador;
}Bote;

#include "visualizacao_grafica.h"

void cria_botes(char* jogador1, char* jogador2);

void imprime_botes(BITMAP *destino);

/* funcoes de acesso as informacoes do bote */
int pega_y_da_base_do_bote(int id);
int pega_x_da_base_do_bote(int id);
int pega_direcao_do_bote(int id);
int pega_velocidade_do_bote(int id);
int bote_lotado(int id);
int bote_ancorado(int id);
int pega_numero_de_passageiros_a_bordo(int id);
int pega_numero_de_vidas_do_bote(int id);
int pega_pontuacao_do_bote(int id);
char* pega_nome_do_jogador(int id);
int bote_afundou(int id);
int botes_afundaram();
char* pega_nome_do_vencedor();
Bote pega_bote(int id);

/* funcoes de atualizacoes das informacoes do bote*/
void seta_direcao_do_bote(int id, int nova_direcao);
void seta_y_da_base_do_bote(int id, int novo_y_da_base);
void seta_x_da_base_do_bote(int id, int novo_x_da_base);
void aumenta_numero_de_resgates(int id);
void troca_direcao_do_bote(int id, int direcao);
void descarrega_passageiros(int id);
void atualiza_direcao(int id, int variacao);
void atualiza_velocidade(int id, int variacao);
void atualiza_ancora(int id);
void zera_numero_de_resgates_do_bote(int id);
void bote_perde_uma_vida(int id);


#endif
