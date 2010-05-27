/*
  EP2 - Laboratório de Programação     10/05/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef JOGO_H
#define JOGO_H

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "naufrago.h"
#include "imprime_estado_atual.h"
#include "movimenta_elementos.h"

void seta_frequencia_geracao_passageiros(float frequencia);
void seta_quantidade_inicial_passageiros(int quantidade_inicial);
void seta_quantidade_maxima_passageiros(int quantidade_maxima);
void jogo(int oceano[MAX_LATITUDE][MAX_LONGITUDE], naufrago *passageiros);
void atualiza_jogo(naufrago *passageiros, int tempo, int oceano[][MAX_LONGITUDE]);

#endif
