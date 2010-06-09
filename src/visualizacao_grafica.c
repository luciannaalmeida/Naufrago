/*
  EP3 - Laboratório de Programação     09/06/2010

  Integrantes:
  Lucianna Thomaz Almeida      5893802
  Lucas Rodrigues Colucci      6920251
  Cindy de Albuquerque         4954631
*/

#include "visualizacao_grafica.h"

/* Opção para inicializar a animação com valores padrão. */
void inicializa_janela_padrao(){
  incicializa_janela(RESOLUCAO_VERTICAL, RESOLUCAO_HORIZONTAL);
}

/* Opção para inicializar a animação com valores definidos pelo usuário. */
/* void incicializa_animacao(int bits_cores_grafico, int resolucao_horizontal, int resolucao_vertical){ */
void incicializa_janela(int resolucao_horizontal, int resolucao_vertical){
  int sucesso;
  int bits_cores_grafico;
  
  /*Inicializa o Allegro, o teclado, o mouse e os temporizadores*/
  allegro_init();
  install_keyboard();
  install_mouse();
  install_timer();	
  
  /* guarda a quantidade de cores que a maquina do usuario suporta */
  bits_cores_grafico = desktop_color_depth();
  
  /* se retornou zero, usar 32 bits de cor */
  if(bits_cores_grafico == 0) bits_cores_grafico = 32;
  
  /*determina o número de bits de cores a ser usado pelos graficos*/
  set_color_depth(bits_cores_grafico);
  
  
  /*inicialização do modo grafico*/
  sucesso = set_gfx_mode(GFX_AUTODETECT, resolucao_vertical, resolucao_horizontal, VIRTUAL_VERTICAL, VIRTUAL_HORIZONTAL);
  if ( sucesso != 0 ){
    printf ("Erro ao inicializar o modo gráfico. Encerrando o programa.\n");
    exit (-1);
  }
  
  /* cria um titulo para a janela do jogo */
  set_window_title("Naufrago"); 
}

/* /\* carrega a imagem de um dado arquivo *\/ */
/* BITMAP *carrega_imagem(char *nomeArquivo){ */
/*   BITMAP *bitmap = load_bitmap(nomeArquivo, NULL); */
/*   return bitmap; */
/* } */

/* /\* Insere um bitmap na tela *\/ */
/* void insere_imagem_na_tela(BITMAP *bitmap, int x, int y){ */
/*   draw_sprite(screen, bitmap, x, y); */
/* } */

/* /\* Insere uma figura origem em um local determinado de um destino*\/ */
/* void sobrepoe_figuras(BITMAP *origem, BITMAP *destino, int x, int y, int altura, int largura){ */
/*   blit(origem, destino, 0, 0, x, y, largura, altura); */
/* } */

/* BITMAP* desenha_oceano(){ */
/*   BITMAP *oceano; */
/*   oceano = carrega_imagem("imagens/Oceano.BMP"); */
/*   insere_imagem_na_tela(oceano, 0, 0); */
/*   return oceano; */
/* } */

void desenha_passageiro(BITMAP *destino, int y, int x){
  /*void circlefill(BITMAP *bmp, int x, int y, int  radius, int color); */
  /*int makecol(int  r, int g, int b); */
  circlefill(destino, x, y, RAIO_PASSAGEIRO, makecol(0, 255, 0)); /*green circle*/
  
}

void desenha_colisao(BITMAP *destino, int y, int x){
  /*void circlefill(BITMAP *bmp, int x, int y, int  radius, int color); */
  /*int makecol(int  r, int g, int b); */
  circlefill(destino, x, y, RAIO_PASSAGEIRO, makecol(255, 0, 0)); /*red circle*/
}

void desenha_coral(BITMAP *destino, int y, int x){
  /*void circlefill(BITMAP *bmp, int x, int y, int  radius, int color); */
  /*int makecol(int r, int g, int b); */
  circlefill(destino, x, y, RAIO_CORAL, makecol(255, 100, 50)); /* circle*/
}
