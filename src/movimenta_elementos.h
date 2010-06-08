/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef MOVIMENTA_ELEMENTOS_H
#define MOVIMENTA_ELEMENTOS_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jogo.h"
#include "naufrago.h"

void inicializa_vetor_de_direcoes();
void atualiza_posicoes_dos_elementos(naufrago *passageiros, int qtd_passageiros, int oceano[MAX_LATITUDE][MAX_LONGITUDE]);

#endif
