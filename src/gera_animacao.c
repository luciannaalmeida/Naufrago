/*
  EP2 - Laboratório de Programação     10/05/2010

  Integrantes:
  Lucianna Thomaz Almeida      5893802
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "gera_animacao.h"

void gera_bitmap(int oceano[MAX_LATITUDE][MAX_LONGITUDE]){
	BITMAP *figura_oceano = carrega_figura("/img/oceano.bmp");
	/*TODO Continuar método*/
}

/* Função que cria as figuras estáticas.*/
void cria_figuras(){
	BITMAP *figura_oceano; 
	BITMAP *bote ;
	BITMAP *recifes;
	BITMAP *passageiros;
	
	figura_oceano = create_bitmap(RESOLUCAO_HORIZONTAL, RESOLUCAO_VERTICAL);
	desenha_retangulo(figura_oceano, 0, 0, RESOLUCAO_HORIZONTAL, RESOLUCAO_VERTICAL, AZUL);
	salva_bitmap("/img/oceano.bmp", figura_oceano);

	bote = create_bitmap(LARGURA_BOTE, ALTURA_BOTE);
	desenha_retangulo(bote, 0, 0, LARGURA_BOTE, ALTURA_BOTE, BEGE);
	salva_bitmap("/img/bote.bmp", bote);

	recifes = create_bitmap(RESOLUCAO_HORIZONTAL, RESOLUCAO_VERTICAL);
	desenha_recife(recifes, RESOLUCAO_HORIZONTAL, RESOLUCAO_VERTICAL, CORAL);
	salva_bitmap("/img/recifes.bmp", recifes);

	passageiros = create_bitmap(RAIO_PASSAGEIRO*2, RAIO_PASSAGEIRO*2);
	desenha_circulo(passageiros, RAIO_PASSAGEIRO, RAIO_PASSAGEIRO, RAIO_PASSAGEIRO, SALMAO);
	salva_bitmap("/img/passageiro.bmp", passageiros);
}

/* Função que desenha os recifes aleatoriamente. */
void desenha_recife(BITMAP *recifes, int largura, int altura, int cor){
	/*TODO Fazer função que desenha os recifes aleatoriamente*/
}
