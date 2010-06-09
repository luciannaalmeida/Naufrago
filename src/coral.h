/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef CORAL_H
#define CORAL_H

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "visualizacao_grafica.h"

typedef struct coral{
  int centro_x;
  int centro_y;
}Coral;

Coral vetor_de_corais[10];

/*inicia corais de uma determinada fase do jogo*/
void inicia_corais(int fase, int oceano[MAX_LATITUDE][MAX_LONGITUDE]);
  
/*desenha os corais da fase 1*/
void inicia_fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]);

/* escolhe fase para imprimir */
void escolhe_fase_para_imprimir(int fase);

int esta_dentro_do_oceano(int y, int x);

int esta_em_algum_coral(int y, int x);



#endif
