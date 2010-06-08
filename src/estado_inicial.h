/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef ESTADO_INICIAL_H
#define ESTADO_INICIAL_H

#include "constantes.h"
#include <stdlib.h>
#include <stdio.h>
#include "imprime_estado_atual.h"
#include "jogo.h"
#include "naufrago.h"


naufrago * gera_estado_inicial_oceano(int oceano[MAX_LATITUDE][MAX_LONGITUDE]);
void coloca_agua_oceano(int oceano[MAX_LATITUDE][MAX_LONGITUDE]);


#endif
