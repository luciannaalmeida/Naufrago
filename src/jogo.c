/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "jogo.h"

int oceano[MAX_LATITUDE][MAX_LONGITUDE];
/* quantidade de passageiros no vetor passageiros */
int qtd_atual_passageiros;
/* quantidade atual de passageiros criados + reinicializados */
int qtd_total_de_passageiros_usados_no_jogo = 0;
float frequencia_geracao_passageiros;
int quantidade_inicial_passageiros;
int quantidade_maxima_passageiros;

int acabaram_os_passageiros(){
  int quantidade_total_de_resgates = pega_quantidade_total_de_resgates();
  return (quantidade_total_de_resgates >= quantidade_maxima_passageiros);
}

void aumenta_numero_total_de_passageiros_usados(){
  qtd_total_de_passageiros_usados_no_jogo ++;
}

int pode_colocar_passageiro_no_oceano(){
  return (qtd_total_de_passageiros_usados_no_jogo < quantidade_maxima_passageiros);
}

int pega_quantidade_de_passageiros(){
  return qtd_atual_passageiros;
}

void tira_passageiro_do_oceano(int y, int x){
  oceano[y][x] = AGUA;
}

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
  trata_comandos_do_jogador();
  /* Cria um novo passageiro de acordo com a frequencia de geracao */
  if(qtd_atual_passageiros < quantidade_maxima_passageiros && frequencia_geracao_passageiros != 0){
	if(frequencia_geracao_passageiros < 1 && pode_colocar_passageiro_no_oceano()){
	  if(tempo % (periodo_geracao_passageiros(frequencia_geracao_passageiros)) == 0)
		gera_e_coloca_passageiro_no_oceano(passageiros, qtd_atual_passageiros++, oceano);
	}
	else
	  for(i = 0; i < frequencia_geracao_passageiros && pode_colocar_passageiro_no_oceano(); i++)
		gera_e_coloca_passageiro_no_oceano(passageiros, qtd_atual_passageiros++, oceano);
  }
  
  /* Atualiza posicao dos elementos no oceano */
  atualiza_posicoes_dos_elementos(passageiros, qtd_atual_passageiros, oceano);
}

int acabou_o_jogo(){
  return (botes_afundaram() || acabaram_os_passageiros());
}

/* Funcao para rodar o jogo */
void jogo(){
  int tempo;
  int cont = 1;
  int fase = 1;
  naufrago *passageiros;
  double tempo_inicial, tempo_final, diferenca_de_tempo = 0.0;
  

  /* Gerar as condicoes iniciais do oceano */
  passageiros = gera_estado_inicial_oceano(fase, oceano);

  /* cria e inicializa a janela do jogo */
  inicializa_janela_padrao();

  /* Inicializa a quantidade inicial de passageiros no jogo */
  qtd_atual_passageiros = QTD_INICIAL_PASSAGEIROS;
  inicializa_vetor_de_mensagem();
  

  /* Enquanto nao eh o fim do jogo */
  for(tempo = 1; (tempo < 5000) && (!key[KEY_ESC]); tempo++){
    
    tempo_inicial = clock();
	/* Tempo esperado para ajudar a impressao */
    usleep(10000 - diferenca_de_tempo);  
    
    imprime_oceano(fase, oceano);
    /* Realiza uma rodada do jogo */
    if(acabou_o_jogo()){
      if(cont){
	atualiza_jogo(passageiros, tempo, oceano);
	cont--;
      }
      imprime_fim_de_jogo(screen, pega_nome_do_vencedor());
    }
    else{
      atualiza_jogo(passageiros, tempo, oceano);
      tempo_final = clock();	
      if(CLOCKS_PER_SEC < 1.0)
	diferenca_de_tempo = (tempo_final - tempo_inicial) / CLOCKS_PER_SEC ;
    }
  }

  libera_vetor_de_mensagem();
  free(passageiros);
}
