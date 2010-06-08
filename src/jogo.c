/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "jogo.h"

int qtd_atual_passageiros;
float frequencia_geracao_passageiros;
int quantidade_inicial_passageiros;
int quantidade_maxima_passageiros;

/* Transforma a frequencia em periodo */
int periodo_geracao_passageiros(float frequencia_geracao_passageiros){
  return ((int)(1.0/frequencia_geracao_passageiros));
}

/* Funcao para setar frequencia quando passada como parametro ou para uso nos testes */
void seta_frequencia_geracao_passageiros(float frequencia){
  frequencia_geracao_passageiros = frequencia;
}

/* Funcao para setar quantidade inicial de passageiros */
void seta_quantidade_inicial_passageiros(int quantidade_inicial){
  quantidade_inicial_passageiros = quantidade_inicial;
}

/* Funcao para setar quantidade maxima de passageiros */
void seta_quantidade_maxima_passageiros(int quantidade_maxima){
  quantidade_maxima_passageiros = quantidade_maxima;
}

/* Realiza uma rodada do jogo */
void atualiza_jogo(naufrago *passageiros, int tempo, int oceano[][MAX_LONGITUDE]){
  int i;

  /* Cria um novo passageiro de acordo com a frequencia de geracao */
  if(qtd_atual_passageiros < QTD_MAXIMA_PASSAGEIROS && frequencia_geracao_passageiros != 0){
	if(frequencia_geracao_passageiros < 1){
	  if(tempo % (periodo_geracao_passageiros(frequencia_geracao_passageiros)) == 0)
		gera_e_coloca_passageiro_no_oceano(passageiros, qtd_atual_passageiros++, oceano);
	}
	else
	  for(i = 0; i < frequencia_geracao_passageiros; i++)
		gera_e_coloca_passageiro_no_oceano(passageiros, qtd_atual_passageiros++, oceano);
  }
  
  /* Atualiza posicao dos elementos no oceano */
  atualiza_posicoes_dos_elementos(passageiros, qtd_atual_passageiros, oceano);
}

/* Funcao para rodar o jogo */
void jogo(int oceano[][MAX_LONGITUDE], naufrago *passageiros){
  int tempo;

  /* cria e inicializa a janela do jogo */
  inicializa_janela_padrao();

  imprime_oceano(oceano);

  /* Inicializa a quantidade inicial de passageiros no jogo */
  qtd_atual_passageiros = QTD_INICIAL_PASSAGEIROS;

  /* Enquanto nao eh o fim do jogo */
  for(tempo = 1; (tempo < 500) && (!key[KEY_ESC]); tempo++){
    /* Tempo esperado para ajudar a impressao */
    usleep(500000);  
    
    
    imprime_oceano(oceano);
    
    /* Realiza uma rodada do jogo */
    atualiza_jogo(passageiros, tempo, oceano);
  }
  
  free(passageiros);
}
