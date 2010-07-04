/*
  EP3 - Laboratório de Programação     09/06/2010
  
  Integrantes:
  Lucianna Thomaz Almeida      5893802  
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "colisoes.h"

int distancia_quadratica_entre_centros(int x_elemento_A, int y_elemento_A, int x_elemento_B, int y_elemento_B){
  int distancia_x = x_elemento_A - x_elemento_B;
  int distancia_y = y_elemento_A - y_elemento_B;
  
  return (distancia_x * distancia_x) + (distancia_y * distancia_y);
}

int distancia_quadratica_minima_entre_centros(int raio1, int raio2){
  int distancia_minima = raio1+raio2;
  return distancia_minima*distancia_minima; 
}

/* Inverte direcao que esta sendo seguida */
int inverte_direcao(int direcao_antiga){
  return (direcao_antiga+4)%8;
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


/* Verifica se 2 passageiros colidiram */
int colidiram(naufrago passageiro_A, naufrago passageiro_B){
  int raio, distancia, distancia_minima;
  raio = RAIO_PASSAGEIRO;
  distancia = distancia_quadratica_entre_centros(passageiro_A.coordenada_x, passageiro_A.coordenada_y, 
												 passageiro_B.coordenada_x, passageiro_B.coordenada_y);
  distancia_minima = distancia_quadratica_minima_entre_centros(raio, raio);

  if (distancia <= distancia_minima)
    return 1;
  return 0;
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

/* calcula a distancia quadratica entre os centros do coral e do naufrago */
int distancia_quadratica_entre_coral_e_naufrago(naufrago passageiro, Coral coral){
  int distancia_x = passageiro.coordenada_x - coral.centro_x;
  int distancia_y = passageiro.coordenada_y - coral.centro_y;

  return (distancia_x*distancia_x) + (distancia_y*distancia_y);
}

/* verifica se houve colisao entre o passageiro e o coral */
int colidiu_com_coral(naufrago passageiro, Coral coral){
  int distancia = distancia_quadratica_entre_coral_e_naufrago(passageiro, coral);
  int distancia_minima = distancia_quadratica_minima_entre_centros(RAIO_PASSAGEIRO, RAIO_CORAL);

  if(distancia <= distancia_minima)
    return 1;
  return 0;
}

/* traca a colisao de um passageiro com um coral */
void trata_colisao_com_coral(naufrago* passageiros, int qtd_passageiros){
  int i, j;
  for(i = 0; i < qtd_passageiros; i++){
    for(j = 0; j< NUMERO_DE_CORAIS; j++){
      if(colidiu_com_coral(passageiros[i], vetor_de_corais[j]))
		passageiros[i].direcao = inverte_direcao(passageiros[i].direcao);
    }
  }
}

int colidiu_com_asimov(naufrago passageiro){
  int y, x, centro_y, centro_x;
  int minimo_y, maximo_y, minimo_x, maximo_x;
  centro_y = passageiro.coordenada_y;
  centro_x = passageiro.coordenada_x;
  minimo_y = (centro_y - RAIO_PASSAGEIRO);
  maximo_y = (centro_y + RAIO_PASSAGEIRO);
  minimo_x = (centro_x - RAIO_PASSAGEIRO);
  maximo_x = (centro_x + RAIO_PASSAGEIRO);
  for(y = minimo_y; y <= maximo_y; y++)
	for(x = minimo_x; x <= maximo_x; x++)
	  if(esta_dentro_do_oceano(y, x) && esta_no_passageiro(y, x, passageiro) && esta_na_asimov(y,x,0))
		return 1;
  return 0;
}

void trata_colisao_com_asimov(naufrago* passageiros, int qtd_passageiros){
  int i;
  for(i = 0; i < qtd_passageiros; i++){
	if(colidiu_com_asimov(passageiros[i]))
	  passageiros[i].direcao = inverte_direcao(passageiros[i].direcao);
  }
}

int bote_bateu_na_borda_do_oceano(int id, int y, int x){
  if(!esta_no_oceano(y, (x - ALTURA_BOTE/3)) || !esta_no_oceano(y, (x + ALTURA_BOTE/3)) || !esta_no_oceano((y - ALTURA_BOTE), x))
	return 1;
  return 0;
}

int bote_proximo_da_asimov(int id, int y, int x, int delta){
  if(esta_na_asimov(y, (x - ALTURA_BOTE/3), delta) || 
     esta_na_asimov(y, (x + ALTURA_BOTE/3), delta) || 
     esta_na_asimov((y - ALTURA_BOTE), x, delta))
	return 1;
  return 0;
}

int bote_bateu_no_coral(int id, int y, int x){
  if(esta_em_algum_coral(y, (x-ALTURA_BOTE/3)) || 
     esta_em_algum_coral(y, (x+ALTURA_BOTE/3)) || 
     esta_em_algum_coral((y-ALTURA_BOTE), x)){
    bote_perde_uma_vida(id);
    zera_numero_de_resgates_do_bote(id);
	return 1;
  }
  return 0;
}

void trata_colisao_do_bote_com_os_elementos_estaticos(int id){
  int direcao_antiga;
  int y, x;
  y = pega_y_da_base_do_bote(id);
  x = pega_x_da_base_do_bote(id);

  if(bote_bateu_na_borda_do_oceano(id, y, x) || bote_proximo_da_asimov(id, y, x, 0) || bote_bateu_no_coral(id, y, x)){
    direcao_antiga = pega_direcao_do_bote(id);
    seta_direcao_do_bote(id, inverte_direcao(direcao_antiga));
  }
}

int vertices_do_bote_batem_no_passageiro(naufrago passageiro, int y, int x){
  if(esta_no_passageiro(y, (x - ALTURA_BOTE/3), passageiro) || 
	 esta_no_passageiro(y, (x + ALTURA_BOTE/3), passageiro) || 
	 esta_no_passageiro((y - ALTURA_BOTE),   x, passageiro))
	return 1;
  return 0;
}

int circunferencia_colide_com_bote(int y, int x, int raio, int y_bote, int x_bote){
  int centro_y, centro_x;
  int distancia_minima, distancia_atual;
  centro_y = y_bote - (ALTURA_BOTE/3);
  centro_x = x_bote;

  distancia_minima = distancia_quadratica_minima_entre_centros(raio, (ALTURA_BOTE/3));
  distancia_atual = distancia_quadratica_entre_centros(centro_x, centro_y, x, y);
  if(distancia_atual <= distancia_minima)
	return 1;
  return 0;
}

void inverte_direcao_do_passageiro(naufrago *passageiros, int id){
  passageiros[id].direcao = inverte_direcao(passageiros[id].direcao);
}

/* para os calculos de colisao, usaremos uma circunferencia inscrita ao bote e os seus 3 vertices para comparacoes */
void trata_colisao_do_bote_com_passageiros(int id_bote, naufrago *passageiros){
  int i, y, x, quantidade_de_passageiros;
  y = pega_y_da_base_do_bote(id_bote);
  x = pega_x_da_base_do_bote(id_bote);

  /* pega a quantidade atual de passageiros */
  quantidade_de_passageiros = pega_quantidade_de_passageiros();

  /* percorre todos os passageiros verificando se eles foram pegos pelo bote */
  for(i = 0; i < quantidade_de_passageiros; i++){
    if(vertices_do_bote_batem_no_passageiro(passageiros[i], y, x) || 
       circunferencia_colide_com_bote(passageiros[i].coordenada_y, passageiros[i].coordenada_x, RAIO_PASSAGEIRO, y, x)){ 
      if(bote_lotado(id_bote) || bote_ancorado(id_bote))
	inverte_direcao_do_passageiro(passageiros, i);
      else{
	passageiros[i] = reinicializa_passageiro(passageiros[i]);
	aumenta_numero_de_resgates(id_bote);
      }
    }
  }
}

int botes_colidiram(){
  int raio = (ALTURA_BOTE/3);
  Bote bote0, bote1;
  
  bote0 = pega_bote(0);
  bote1 = pega_bote(1);
  
  if(circunferencia_colide_com_bote(bote0.coordenada_y, bote0.coordenada_x, 
				    raio, bote1.coordenada_y, bote1.coordenada_x) ||
     circunferencia_colide_com_bote(bote0.coordenada_y, (bote0.coordenada_x - raio),
				    0, bote1.coordenada_y, bote1.coordenada_x) ||
     circunferencia_colide_com_bote(bote0.coordenada_y, (bote0.coordenada_x + raio), 
				    0, bote1.coordenada_y, bote1.coordenada_x) ||
     circunferencia_colide_com_bote((bote0.coordenada_y - raio*3), bote0.coordenada_x, 
				    0, bote1.coordenada_y, bote1.coordenada_x) ||
     circunferencia_colide_com_bote(bote1.coordenada_y, (bote1.coordenada_x - raio), 
				    0, bote0.coordenada_y, bote0.coordenada_x) ||
     circunferencia_colide_com_bote(bote1.coordenada_y, (bote1.coordenada_x + raio), 
				    0, bote0.coordenada_y, bote0.coordenada_x) ||
     circunferencia_colide_com_bote((bote1.coordenada_y - raio*3), bote1.coordenada_x, 
				    0, bote0.coordenada_y, bote0.coordenada_x))
    return 1;
  
  return 0;
}

void trata_colisao_entre_botes(){
  int direcao_aux;
  if(botes_colidiram() && !bote_afundou(0) && !bote_afundou(1)){
	direcao_aux = pega_direcao_do_bote(0);
	troca_direcao_do_bote(0, pega_direcao_do_bote(1));
	troca_direcao_do_bote(1, direcao_aux);
  }
}

int bote_pode_descarregar(int id_bote){
  int y, x;
  y = pega_y_da_base_do_bote(id_bote);
  x = pega_x_da_base_do_bote(id_bote);

  return(bote_ancorado(id_bote) && bote_proximo_da_asimov(id_bote, y, x, DISTANCIA_MIN_PARA_DESCARREGAR));
}

void trata_colisoes_do_bote(int id_bote, naufrago *passageiros){
  trata_colisao_do_bote_com_passageiros(id_bote, passageiros);
  trata_colisao_entre_botes();  
  if(bote_pode_descarregar(id_bote))
    descarrega_passageiros(id_bote);
  else
    trata_colisao_do_bote_com_os_elementos_estaticos(id_bote);  
}
