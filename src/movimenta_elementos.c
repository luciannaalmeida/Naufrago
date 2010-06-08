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

int distancia_quadratica_entre_centros(naufrago elemento_A, naufrago elemento_B){
  int distancia_abcissa = elemento_A.coordenada_x - elemento_B.coordenada_x;
  int distancia_ordenada = elemento_A.coordenada_y - elemento_B.coordenada_y;
  
  return (distancia_abcissa*distancia_abcissa) + (distancia_ordenada*distancia_ordenada);
}

int distancia_quadratica_minima_entre_centros(int raio1, int raio2){
  int distancia_minima = raio1+raio2;
  return distancia_minima*distancia_minima; 
}

/* Verifica se passageiros colidiram */
int colidiram(naufrago passageiro_A, naufrago passageiro_B){
  /* if(passageiro_A.coordenada_x == passageiro_B.coordenada_x && */
  /* 	 passageiro_A.coordenada_y == passageiro_B.coordenada_y  ) */
  int raio = RAIO_PASSAGEIRO;
  int distancia = distancia_quadratica_entre_centros(passageiro_A, passageiro_B);
  int distancia_minima = distancia_quadratica_minima_entre_centros(raio, raio);

  if (distancia <= distancia_minima){
    printf("distancia entre centros - %d         distancia minima - %d\n", distancia, distancia_minima);
    printf("passageiro_A.coordenada_x %d passageiro_A.coordenada_y %d \n" 
	   "passageiro_B.coordenada_x %d passageiro_B.coordenada_y %d \n"
	   "passageiro_A.direcao %d  passageiro_B.direcao %d\n"
	   "passageiro_A.id %d passageiro_B.id %d\n\n",
	   passageiro_A.coordenada_x , passageiro_A.coordenada_y ,   
	   passageiro_B.coordenada_x , passageiro_B.coordenada_y ,
	   passageiro_A.direcao,  passageiro_B.direcao,
	   passageiro_A.id, passageiro_B.id);
    
    return 1;
  }
  return 0;
}

/* Inverte direcao que esta sendo seguida */
int inverte_direcao(int direcao_antiga){
  switch(direcao_antiga){
  case 0:
	return 7;
  case 1:
	return 6;
  case 2:
	return 5;
  case 3:
	return 4;
  case 4:
	return 3;
  case 5:
	return 2;
  case 6:
	return 1;		
  case 7:
	return 0;
  }
  return direcao_antiga;
}

/* Troca vetor velocidade do passageiro A com o B */
void troca_vetor_velocidade_dos_passageiros(naufrago *passageiros, int id_A, int id_B){
  int direcao_aux;
  int velocidade_aux;
  velocidade_aux = passageiros[id_A].modulo_velocidade;
  direcao_aux = passageiros[id_A].direcao;

  passageiros[id_A].modulo_velocidade = passageiros[id_B].modulo_velocidade;
  passageiros[id_A].direcao = passageiros[id_B].direcao;

  passageiros[id_B].modulo_velocidade = velocidade_aux;
  passageiros[id_B].direcao = direcao_aux;
}

/* Inverte a direcao do vetor velocidade de um dos elementos depois troca os vetores dos passageiros */
void troca_vetor_velocidade_de_passageiros_com_mesma_direcao(naufrago *passageiros, int id_A, int id_B){
  if(passageiros[id_A].modulo_velocidade < passageiros[id_B].modulo_velocidade)
	passageiros[id_A].direcao = inverte_direcao(passageiros[id_A].direcao);
  else
	passageiros[id_B].direcao = inverte_direcao(passageiros[id_B].direcao);
  /* Funcao que troca o vetor velocidade dos elementos */
  troca_vetor_velocidade_dos_passageiros(passageiros, id_A, id_B);
}

/* Inverte a direcao dos passageiros que colidiram */
void trata_colisao_entre_passageiros(naufrago *passageiros, int qtd_passageiros){
  int i, j, numero_colisoes, passageiro_colidido = 0;
  
  for(i = 0; i < qtd_passageiros; i++){
    /* Verifica com quantos passageiros o passageiro i colidiu */
    for(j = 0, numero_colisoes = 0; j < qtd_passageiros; j++)
      if(i != j && colidiram(passageiros[i], passageiros[j])){
	passageiro_colidido = j;
	numero_colisoes++;
      }
    
    if(numero_colisoes >= 1){
      /* Verifica se o passageiro colidiu com apenas um outro passageiro */
      if(numero_colisoes == 1 && i < j){
	if(passageiros[i].direcao == passageiros[j].direcao)
	  troca_vetor_velocidade_de_passageiros_com_mesma_direcao(passageiros, i, j);
	else
	  troca_vetor_velocidade_dos_passageiros(passageiros, i, passageiro_colidido);
      }
      
      /* Inverte a direcao do passageiro no caso de ter ocorrido alguma colisao (numero_colisoes > 1) */
      else if(numero_colisoes > 1)
	passageiros[i].direcao = inverte_direcao(passageiros[i].direcao);
      
      /* Marca no passageiro que ocorreu colisao */
      passageiros[i].houve_colisao = 1;
    }
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
}
