/*
  EP4 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#ifndef CONSTANTES_H
#define CONSTANTES_H


#define VEL_MEDIA_PASSAGEIROS      75
#define VEL_MAX_PASSAGEIROS       100
#define VEL_MIN_PASSAGEIROS        50
#define RAIO_PASSAGEIRO            5
#define RAIO_CORAL                 200

#define FREQ_GERACAO_PASSAGEIROS   10
#define QTD_INICIAL_PASSAGEIROS    60
#define QTD_MAXIMA_PASSAGEIROS    100

/* Valores padrão para inicialização do Allegro.*/

#define RESOLUCAO_HORIZONTAL   1024
#define RESOLUCAO_VERTICAL     768
#define VIRTUAL_HORIZONTAL      0
#define VIRTUAL_VERTICAL        0

#define AGUA 0
#define PASSAGEIRO 1
#define CORAL -1
#define ASIMOV -2
#define BOTE -3

#define NUMERO_DE_CORAIS 4

#define y1_ASIMOV 300
#define x1_ASIMOV 450
#define y2_ASIMOV 400
#define x2_ASIMOV 550

/* define distancia minima entre bote e asimov para descarregar passageiros */
#define DISTANCIA_MIN_PARA_DESCARREGAR 30
#define NUMERO_INICIAL_DE_VIDAS 3
#define PONTUACAO_PARA_GANHAR_VIDA 500
#define PONTUACAO_DE_RESGATE 10
#define PONTUACAO_DE_DESCARREGO 20

#define MINIMO_DE_CLICKS 7

#define ALTURA_BOTE  30
#define MAX_VEL_BOTE 4
#define LOTACAO_DO_BOTE 10

#define MAX_LONGITUDE  1024
#define MAX_LATITUDE   768

#define _XOPEN_SOURCE 500
#define _SVID_SOURCE 1
#define DELAY 1000
#define REPEAT 0

#define esta_no_oceano(y, x) (((x) < 0 || (x) >= MAX_LONGITUDE || (y) < 0 || (y) >= MAX_LATITUDE) ? 0 : 1)

#endif
