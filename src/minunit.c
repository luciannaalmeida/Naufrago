/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constantes.h"
#include "estado_inicial.h"
#include "movimenta_elementos.h"
#include "jogo.h"
#include "naufrago.h"

static int oceano[MAX_LATITUDE][MAX_LONGITUDE];     /*matriz que representa o oceano*/
static naufrago* passageiros;                       /*vetor de passageiros*/

/*Verifica se o programa eh instavel em uma velocidade alta*/
void verifica_velocidades_altas(){
  int velocidade_alta = 50;                    /*Como a velocidade maxima eh 100, a velocidade media maxima tem que ser 50*/
  int i;                                       /*contador de iteracoes*/

  /*seta a velocidade media como 50*/
  seta_velocidade_media_passageiros(velocidade_alta);

  /*gera o estado inicial do oceano, com os passageiros recebendo suas posicoes iniciais*/
  passageiros = gera_estado_inicial_oceano(1, oceano);
  
  /*inicia as iteracoes*/
  for(i=0; i<10000; i++)
    atualiza_jogo(passageiros, i, oceano);     /*atualiza o jogo*/
  
  /*Se nao deu nenhum problema, quer dizer que passou nos testes*/
  printf("Passou nos testes de altas velocidades\n");
}

/*Verifica se o programa eh instavel em uma velocidade baixa*/
void verifica_velocidades_baixas(){
  int velocidade_baixa = 1;                     /*menor velocidade possivel no nosso ep, equivalente a 0.1 pixels por seg.*/
  int i;                                        /*contador de iteracoes*/

  
  /*seta a velocidade media como 1*/
  seta_velocidade_media_passageiros(velocidade_baixa);

  /*gera o estado inicial do oceano, com os passageiros recebendo suas posicoes iniciais*/
  passageiros = gera_estado_inicial_oceano(1, oceano);

  /*inicia as iteracoes*/
  for(i=0; i<10000; i++)
    atualiza_jogo(passageiros, i, oceano);       /*atualiza o jogo*/
  
  /*Se nao deu nenhum problema, quer dizer que passou nos testes*/  
  printf("Passou nos testes de baixas velocidades\n");
}

/*Verifica se o programa eh instavel em uma ferquencia alta*/
void verifica_frequencias_altas(){
  float frequencia_alta = 100.0;                     /*maior frequencia possivel equivalente ao i maximo*/
  int quantidade_maxima_possivel = 342;             /*numero maximo de passageiros em uma matriz 1024 x 728*/
  int i;                                             /*contador de iteracoes*/


  /*quantidade mazima de passageiros eh aumentada para leva o teste ao extremo*/
  seta_quantidade_maxima_passageiros(quantidade_maxima_possivel);

  /*seta a frequencia como 100*/
  seta_frequencia_geracao_passageiros(frequencia_alta);

  /*gera o estado inicial do oceano, com os passageiros recebendo suas posicoes iniciais*/
  passageiros = gera_estado_inicial_oceano(1, oceano);

  /*como o i maximo multiplicado pela frequencia deve ser menor do que o numero de pixels */
  /*na tela, eu diferenciei o i dos outros testes para nao ficar em loop.*/
  for(i=0; i<30; i++) 
    atualiza_jogo(passageiros, i, oceano);           /*atualiza o jogo*/
  
  /*Se nao deu nenhum problema, quer dizer que passou nos testes*/  
  printf("Passou nos testes de altas frequencias\n");
}

/*Verifica se o programa eh instavel em uma frequencia baixa*/
void verifica_frequencias_baixas(){
  float frequencia_baixa = 0.001;                     /*Uma frequencia muito baixa*/
  int i;                                              /*contador de iteracoes*/


  /*seta a frequencia como 0.001*/
  seta_frequencia_geracao_passageiros(frequencia_baixa);

  /*gera o estado inicial do oceano, com os passageiros recebendo suas posicoes iniciais*/
  passageiros = gera_estado_inicial_oceano(1, oceano);

  /*inicia as iteracoes*/  
  for(i=0; i<1000; i++)
    atualiza_jogo(passageiros, i, oceano);            /*atualiza o jogo*/
  
  /*Se nao deu nenhum problema, quer dizer que passou nos testes*/  
  printf("Passou nos testes de baixas frequencias\n\n");
}

void gera_passageiros_personalizados(int i, float modulo_velocidade, int direcao, int coordenada_x, int coordenada_y){
 /* Salvar o id do passageiro */
  passageiros[i].id = i;
  
  passageiros[i].modulo_velocidade = modulo_velocidade;
  passageiros[i].direcao = direcao;
  passageiros[i].houve_colisao = 0;
  passageiros[i].tempo_no_lugar = 0;

  passageiros[i].coordenada_x = coordenada_x;
  passageiros[i].coordenada_y = coordenada_y;
  
  oceano[passageiros[i].coordenada_y][passageiros[i].coordenada_x] += PASSAGEIRO;
}

int passageiro_esta_na_posicao(int id, int x, int y){
  return (passageiros[id].coordenada_x == x && 
	  passageiros[id].coordenada_y == y);
}


/*verifica a colisao de dois elementos*/
void verifica_colisoes_entre_2_elementos(){
  int i;

  /*verifica quando os passageiros estao na mesma direcao*/
  gera_passageiros_personalizados(0, 100, 4, 15, 15);
  gera_passageiros_personalizados(1, 100, 3, 17, 15);
  for(i=0; i<2; i++)
    atualiza_jogo(passageiros, i, oceano);
  if(!(passageiro_esta_na_posicao(0, 15, 15) && passageiro_esta_na_posicao(1, 17, 15))){
    printf("Colisao de passageiros na mesma direcao e sentidos opostos falhou\n");
    exit(1);
  }
}
/*Calcula as estatisticas do programa*/
void calcula_estatisticas(){
  int soma_de_velocidades = 0;               /*soma as velocidades obtidas*/
  int media_de_velocidades;                  /*media das velocidades obtidas*/
  int velocidade_aux;                        /*auxilia no calculo das veloc. max. e min.*/
  int velocidade_maxima = 0;                 /*velocidade maxima obtida*/
  int velocidade_minima = 100;               /*velocidade minima obtida*/
  int t, i;                                  /*contadores*/

  srand(time(NULL));

  /*impressao de constantes*/
  printf("Constantes :\n");
  printf(" - MAX_LONGITUDE = %d\n", MAX_LONGITUDE);
  printf(" - MAX_LATITUDE = %d\n", MAX_LATITUDE);
  printf(" - AGUA = %d\n", AGUA);
  printf(" - PASSAGEIRO = %d\n", PASSAGEIRO);
  printf(" - FREQ_GERACAO_PASSAGEIROS = %d\n", FREQ_GERACAO_PASSAGEIROS);
  printf(" - QTD_INICIAL_PASSAGEIROS = %d\n", QTD_INICIAL_PASSAGEIROS);
  printf(" - QTD_MAXIMA_PASSAGEIROS = %d\n", QTD_MAXIMA_PASSAGEIROS);


  /*comeca a interacao para 50, 100, 150, ..., 300 "segundos"*/
  for(t=50; t < 500; t=t+50){
    velocidade_aux = 0;
    velocidade_maxima = 0;
    velocidade_minima = 100;
    soma_de_velocidades = 0;
    media_de_velocidades = 0;

    for(i=0; i<t; i++){
      velocidade_aux = gera_velocidade_passageiro_aleatoria();
      
      if(velocidade_aux > velocidade_maxima)
	velocidade_maxima = velocidade_aux;

      if (velocidade_minima > velocidade_aux)
	velocidade_minima = velocidade_aux;
      
      soma_de_velocidades += velocidade_aux;
    }
    
    media_de_velocidades = soma_de_velocidades / t;
    /*imprime os resultados obtidos*/
    printf("INFORMACOES NO TEMPO t = %d: \n", t);
    printf(" - VELOCIDADE MAXIMA = %d\n", velocidade_maxima);  
    printf(" - VELOCIDADE MINIMA = %d\n", velocidade_minima);
    printf(" - VELOCIDADE MEDIA  = %d\n", media_de_velocidades);
  }
}

/*Chama todos os testes acima*/
int faz_todos_os_testes() {
  verifica_velocidades_altas();
  verifica_velocidades_baixas();
  verifica_frequencias_altas();
  verifica_frequencias_baixas();
  verifica_colisoes_entre_2_elementos();
  calcula_estatisticas();
  return 0;
}

int main(int argc, char **argv) {
  /*Facilita a visualizacao*/
  printf("\n\n");          
   
  faz_todos_os_testes();

  /*inicia vetor com as direcoes*/
  inicializa_vetor_de_direcoes();
  
  /*Soh chega aqui se todos os testes passaram*/
  printf("Todos os testes passaram!\n");
    
  return 0;
}
