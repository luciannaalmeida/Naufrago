#ifndef CORAL_H
#define CORAL_H

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "visualizacao_grafica.h"

typedef struct coral{
  int x;
  int y;
}posicao_do_coral;

posicao_do_coral vetor_posicao_dos_corais[3];

/*inicia corais de uma determinada fase do jogo*/
void inicia_corais(int fase, int oceano[MAX_LATITUDE][MAX_LONGITUDE]);
  
/*desenha os corais da fase 1*/
void fase1(int oceano[MAX_LATITUDE][MAX_LONGITUDE]);




#endif
