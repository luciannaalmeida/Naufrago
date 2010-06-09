/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "movimenta_elementos.h"

/*0  1  2*/
/*3     4*/
/*5  6  7*/

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
  define_valores_da_direcao(3, -1,  0);
  define_valores_da_direcao(4,  1,  0);
  define_valores_da_direcao(5, -1, -1);
  define_valores_da_direcao(6,  0, -1);
  define_valores_da_direcao(7,  1, -1);
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
  if(esta_fora_do_oceano(passageiro))
    passageiro = reinicializa_passageiro(passageiro);

  return passageiro;
}

/* Atualiza a posicao do elemento no oceano */
naufrago atualiza_posicao_do_elemento_no_oceano(naufrago passageiro, int oceano[][MAX_LONGITUDE]){
  /* Desmarca a posicao antiga do passageiro */
  oceano[passageiro.coordenada_y][passageiro.coordenada_x] -= PASSAGEIRO;
  /* Calcula a nova posicao do passageiro */
  passageiro = calcula_nova_posicao_do_elemento(passageiro);
  /* Marca a nova posicao do passageiro no oceano */
  oceano[passageiro.coordenada_y][passageiro.coordenada_x] += PASSAGEIRO;
	
  return passageiro;
}



/* Atualiza a posicao de todos os elementos */
void atualiza_posicoes_dos_elementos(naufrago *passageiros, int qtd_passageiros, int oceano[][MAX_LONGITUDE]){
  int i;

  for(i = 0; i < qtd_passageiros; i++){

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
  
  /* Verifica e trata as colisoes */
  trata_colisao_entre_passageiros(passageiros, qtd_passageiros);
  trata_colisao_com_coral(passageiros, qtd_passageiros);
  trata_colisao_com_asimov(passageiros, qtd_passageiros);
}
