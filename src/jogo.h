/*
  EP3 - Laboratório de Programação     09/06/2010
  
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
#include <allegro.h>
#include <time.h>
#include "naufrago.h"
#include "visualizacao_grafica.h"
#include "imprime_estado_atual.h"
#include "movimenta_elementos.h"
#include "estado_inicial.h"
#include "teclas.h"
#include "imprime_informacoes.h"

void tira_passageiro_do_oceano(int y, int x);
int pega_quantidade_de_passageiros();
void seta_frequencia_geracao_passageiros(float frequencia);
void seta_quantidade_inicial_passageiros(int quantidade_inicial);
void seta_quantidade_maxima_passageiros(int quantidade_maxima);
void jogo();
void atualiza_jogo(naufrago *passageiros, int tempo, int oceano[][MAX_LONGITUDE]);

#endif
