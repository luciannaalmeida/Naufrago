/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef ASIMOV_H
#define ASIMOV_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "visualizacao_grafica.h"

int esta_na_asimov(int y, int x, int delta_de_aproximacao);
void cria_asimov(int oceano[][MAX_LONGITUDE]);
void imprime_asimov(BITMAP *destino);

#endif
