/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef IMPRIME_INFORMACOES_H
#define IMPRIME_INFORMACOES_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>
#include "bote.h"

void imprime_informacoes(BITMAP *destino);
void inicializa_vetor_de_mensagem();
void libera_vetor_de_mensagem();
void imprime_fim_de_jogo(BITMAP *destino, char* vencedor);

#endif
