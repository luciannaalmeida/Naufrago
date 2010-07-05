/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "movimenta_elementos.h"

/*0  1  2*/
/*7     3*/
/*6  5  4*/


/* Estrutura que indica uma das possiveis direcoes do passageiro */
typedef struct direcao{
  int deslocamento_em_x;
  int deslocamento_em_y;
}Direcao;

/* Cria vetor que guarda as 8 direcoes possiveis */
Direcao direcoes[8];


void define_valores_da_direcao(int i, int x, int y){
  direcoes[i].deslocamento_em_x = x;
  direcoes[i].deslocamento_em_y = y;
}

/* Seta as 8 direcoes possiveis */
void inicializa_vetor_de_direcoes(){
  define_valores_da_direcao(0, -1,  1);
  define_valores_da_direcao(1,  0,  1);
  define_valores_da_direcao(2,  1,  1);
  define_valores_da_direcao(3,  1,  0);
  define_valores_da_direcao(4,  1, -1);
  define_valores_da_direcao(5,  0, -1);
  define_valores_da_direcao(6, -1, -1);
  define_valores_da_direcao(7, -1,  0);

}


void calcula_nova_direcao(naufrago* passageiros, int i, int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
  int fator_direcao = rand()%100;

  /* Calcula nova direcao seguindo a regra da cadeia de markov com 65% de chace de nao trocar e 5% para cada direcao restante */
  if(fator_direcao >= 65){
    fator_direcao = ((fator_direcao - 64) / 5) + 1;
    passageiros[i].direcao = (passageiros[i].direcao + fator_direcao) % 8;
  }
}


/* Calcula a nova posicao do elemento de acordo com a sua direcao */
naufrago calcula_nova_posicao_do_elemento(naufrago passageiro){
  passageiro.coordenada_x += direcoes[passageiro.direcao].deslocamento_em_x;
  passageiro.coordenada_y += direcoes[passageiro.direcao].deslocamento_em_y;

  /* Coloca passageiro em uma das bordas caso ele tenha saido do oceano */
  if(!esta_no_oceano(passageiro.coordenada_y, passageiro.coordenada_x))
    passageiro = reinicializa_passageiro(passageiro);

  return passageiro;
}

/* Atualiza a posicao do elemento no oceano */
naufrago atualiza_posicao_do_elemento_no_oceano(naufrago passageiro, int oceano[][MAX_LONGITUDE]){
  if(esta_no_oceano(passageiro.coordenada_y, passageiro.coordenada_x)){
    /* Desmarca a posicao antiga do passageiro */
    oceano[passageiro.coordenada_y][passageiro.coordenada_x] -= PASSAGEIRO;
    /* Calcula a nova posicao do passageiro */
    passageiro = calcula_nova_posicao_do_elemento(passageiro);
    /* Marca a nova posicao do passageiro no oceano */
    oceano[passageiro.coordenada_y][passageiro.coordenada_x] += PASSAGEIRO;
  }
  return passageiro;
}

void movimenta_passageiros(naufrago *passageiros, int qtd_passageiros, int oceano[][MAX_LONGITUDE]){
  int i;
  for(i = 0; i < qtd_passageiros; i++){
    if(passageiro_esta_no_jogo(passageiros[i])){
      /* Se nao houve colisao e nao passou tempo suficiente para o passageiro mudar de lugar, tempo_no_lugar eh acrescido */
      if((passageiros[i].houve_colisao == 0) && (passageiros[i].tempo_no_lugar == (100 - passageiros[i].modulo_velocidade + 1))){
	passageiros[i].tempo_no_lugar ++;
      }
      else{ 
	/* Verifica se o passageiro havia colidido com alguma coisa na ultima rodada. Se sim, sua direcao nao sera recalculada */	  
	/* Se nao havia colidido, calcula nova direcao normalmente */
	if(passageiros[i].houve_colisao == 0)
	  calcula_nova_direcao(passageiros, i, oceano);
	
	/* Seta houve_colisao e tempo_no_lugar */
	passageiros[i].houve_colisao = 0;
	passageiros[i].tempo_no_lugar = 1;
	
	/* Muda o passageiro de lugar no oceano */
	passageiros[i] = atualiza_posicao_do_elemento_no_oceano(passageiros[i], oceano);
      }
    }
  }
  /* Verifica e trata as colisoes */
  trata_colisao_entre_passageiros(passageiros, qtd_passageiros);
  trata_colisao_com_coral(passageiros, qtd_passageiros);
  trata_colisao_com_asimov(passageiros, qtd_passageiros);
}

/* Calcula a nova posicao do bote de acordo com a sua direcao */
void calcula_nova_posicao_do_bote(int id){
  int direcao_do_bote, novo_x_da_base, novo_y_da_base, velocidade;
  velocidade = pega_velocidade_do_bote(id);

  /* pega direcao do bote */
  direcao_do_bote = pega_direcao_do_bote(id);

  /* atualiza o x da base do bote */
  novo_x_da_base = pega_x_da_base_do_bote(id) + direcoes[direcao_do_bote].deslocamento_em_x*velocidade;
  seta_x_da_base_do_bote(id, novo_x_da_base);

  /* atualiza o y da base do bote */
  novo_y_da_base = pega_y_da_base_do_bote(id) + direcoes[direcao_do_bote].deslocamento_em_y*velocidade;
  seta_y_da_base_do_bote(id, novo_y_da_base);
}

void movimenta_botes(naufrago *passageiros, int qnt_passageiros, int oceano[][MAX_LONGITUDE]){
  int id;
  for(id = 0; id < 2; id++){
    if(!bote_afundou(id)){
      calcula_nova_posicao_do_bote(id);
      trata_colisoes_do_bote(id, passageiros);
    }
  }
}

/* Atualiza a posicao de todos os elementos */
void atualiza_posicoes_dos_elementos(naufrago *passageiros, int qtd_passageiros, int oceano[][MAX_LONGITUDE]){
  movimenta_botes(passageiros, qtd_passageiros, oceano);
  movimenta_passageiros(passageiros, qtd_passageiros, oceano);
}
