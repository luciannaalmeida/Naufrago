/*
  EP2 - Laboratório de Programação     10/05/2010

  Integrantes:
  Lucianna Thomaz Almeida      5893802
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include <stdio.h>
#include <stdlib.h>
#include "animacao.h"

/* Opção para inicializar a animação com valores padrão. */
void inicializa_padrao(){
	incicializa_animacao(BITS_CORES_GRAFICO, RESOLUCAO_HORIZONTAL, RESOLUCAO_VERTICAL);
}

/* Opção para inicializar a animação com valores definidos pelo usuário. */
void incicializa_animacao(int bits_cores_grafico, int resolucao_horizontal, int resolucao_vertical){
	int sucesso;
	
	/*Inicializa o Allegro, o teclado, o mouse e os temporizadores*/
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();

	/*determina o número de bits de cores a ser usado pelos gráficos*/
	set_color_depth(bits_cores_grafico);

	/*inicialização do modo gráfico*/
	sucesso = set_gfx_mode(GFX_AUTODETECT, resolucao_horizontal, resolucao_vertical, VIRTUAL_HORIZONTAL, VIRTUAL_VERTICAL);
	if ( sucesso < 0 ){
		printf ("Erro ao inicializar o modo gráfico. Encerrando o programa.\n");
		exit (-1);
	}
}

/* Carrega uma figura de um dado arquivo */
BITMAP *carrega_figura(char *nomeArquivo){
	BITMAP *bitmap = load_bitmap(nomeArquivo, NULL);
	return bitmap;
}

/* Insere uma figura origem em um local determinado de um destino*/
void sobrepoe_figuras(BITMAP *origem, BITMAP *destino, int x_inicial, int y_inicial, int altura, int largura){
	blit(origem, destino, 0, 0, x_inicial, y_inicial, largura, altura);
}

/* Insere um bitmap na tela */
void insere_figura_tela(BITMAP *bitmap){
	draw_sprite(screen, bitmap, 0, 0);
}

/* Desenha um círculo centrado nas coordenadas x e y.*/
void desenha_circulo(BITMAP *bitmap, int x, int y, int raio, int cor){
	circlefill(bitmap, x, y, raio, cor);
}

/* Desenha um retângulo entre as coordenadas x_inicial, x_final, y_inicial e y_final.*/
void desenha_retangulo(BITMAP *bitmap, int x_inicial, int y_inicial, int x_final, int y_final, int cor){
	rectfill(bitmap, x_inicial, y_inicial, x_final, y_final, cor);
}

void salva_bitmap(char *filename, BITMAP *bmp){
	save_bitmap(filename, bmp, NULL);
}

void finaliza_animacao(){
	allegro_exit();
}
