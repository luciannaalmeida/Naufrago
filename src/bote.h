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
}Bote;

#include "visualizacao_grafica.h"

Bote botes[2];

void cria_botes();

void imprime_botes(BITMAP *destino);

#endif
