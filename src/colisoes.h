/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef COLISOES_H
#define COLISOES_H

#include <stdlib.h>
#include <stdio.h>
#include "naufrago.h"
#include "coral.h"
#include "asimov.h"
#include "jogo.h"

int distancia_quadratica_entre_centros(int x_elemento_A, int y_elemento_A, int x_elemento_B, int y_elemento_B);

int distancia_quadratica_minima_entre_centros(int raio1, int raio2);

/* Inverte direcao que esta sendo seguida */
int inverte_direcao(int direcao_antiga);

/* Troca vetor velocidade do passageiro A com o B */
void troca_vetor_velocidade_dos_passageiros(naufrago *passageiros, int id_A, int id_B);

/* Inverte a direcao do vetor velocidade de um dos elementos depois troca os vetores dos passageiros */
void troca_vetor_velocidade_de_passageiros_com_mesma_direcao(naufrago *passageiros, int id_A, int id_B);

/* Verifica se 2 passageiros colidiram */
int colidiram(naufrago passageiro_A, naufrago passageiro_B);

/* Inverte a direcao dos passageiros que colidiram */
void trata_colisao_entre_passageiros(naufrago *passageiros, int qtd_passageiros);

int distancia_quadratica_entre_coral_e_naufrago(naufrago passageiro, Coral coral);

int colidiu_com_coral(naufrago passageiro, Coral coral);

void trata_colisao_com_coral(naufrago* passageiros, int qtd_passageiros);

void trata_colisao_com_asimov(naufrago* passageiros, int qtd_passageiros);

void trata_colisoes_do_bote(int id, naufrago *passageiros);

#endif
