/*
  EP2 - Laboratório de Programação     10/05/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estado_inicial.h"
#include "movimenta_elementos.h"
#include "jogo.h"

/* imprime o menu de parametros */
void imprime_help(){
  printf("-h          -->   imprime o menu help.\n");
  printf("-v<valor>   -->   seta o valor da velocidade media\n");
  printf("-s<valor>   -->   seta o valor da semente usada no rand().\n");
  printf("-f<valor>   -->   seta o valor da frequencia de geracao de passageiros.\n");
}

int main(int argc, char* argv[]){
  int semente, quantidade_inicial_passageiros, quantidade_maxima_passageiros;
  float frequencia_geracao_passageiros, velocidade_media_passageiros;
  int oceano[MAX_LATITUDE][MAX_LONGITUDE];
  naufrago *passageiros;
  int i;

  /* Verifica os valores passados pelo usuario:
   * -h          -->   imprime o menu help.
   * -s<valor>   -->   seta o valor da semente usada no rand().
   * -f<valor>   -->   seta o valor da frequencia de geracao de passageiros.
   * -v<valor>   -->   seta o valor da velocidade media.
   */
  
  /*Inicia as variaveis com valores default*/
  semente = time(NULL);
  frequencia_geracao_passageiros = FREQ_GERACAO_PASSAGEIROS;
  velocidade_media_passageiros = VEL_MEDIA_PASSAGEIROS;
  quantidade_inicial_passageiros = QTD_INICIAL_PASSAGEIROS;
  quantidade_maxima_passageiros = QTD_MAXIMA_PASSAGEIROS;
  
  
  if(argc > 1){
    for(i=1; i < argc; i++){
      if (argv[i][0] == '-'){
		switch (argv[i][1]){
		case 'h': 
		  imprime_help();
		  return 0;
		case 'f':
		  frequencia_geracao_passageiros = atof(argv[i] + 2);
		  printf("frequencia %f\n", frequencia_geracao_passageiros);
		  break;
		case 's':
		  semente = atoi(argv[i] + 2);
		  break;
		case 'v':
		  velocidade_media_passageiros = atof(argv[i] + 2);
		  break;
		default:
		  printf("COMANDO INVALIDO. -h PARA AJUDA.\n");
		  return 0;
		}
      }
      else {
		printf("COMANDO INVALIDO. -h PARA AJUDA.\n");
		return 0;
      }
    }
  }

  /* Seta todas as variaveis que podem depender dos parametros passados na linha de comando */
  srand(semente);
  seta_frequencia_geracao_passageiros(frequencia_geracao_passageiros);
  seta_velocidade_media_passageiros(velocidade_media_passageiros);

  /* Inicializa o vetor de direcoes */
  inicializa_vetor_de_direcoes();

  /* Gerar as condicoes iniciais do oceano */
  passageiros = gera_estado_inicial_oceano(oceano);
    
  /* Rodar o jogo */
  jogo(oceano, passageiros);

  return 0;
}

