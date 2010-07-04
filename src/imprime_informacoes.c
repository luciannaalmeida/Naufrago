#include "imprime_informacoes.h"
 
#define TAMANHO 40
char * mensagem;


void inicializa_vetor_de_mensagem(){
  mensagem = malloc(TAMANHO * sizeof(char));
  if(mensagem == NULL){
    printf("Erro na alocacao de memoria\n");
    exit(-1);
  }
}

void libera_vetor_de_mensagem(){
  free(mensagem);
}

void imprime_fim_de_jogo(BITMAP *destino){
  sprintf(mensagem, "GAME OVER");
  textout_ex(destino, font, mensagem, (MAX_LONGITUDE/2)-40, (MAX_LATITUDE/2)-4, makecol(255,255,255), -1);
}

void imprime_vida(int id, int inicio_y, int inicio_x, BITMAP *destino){
  if(bote_afundou(id))
    sprintf(mensagem, "Afundou...");
  else
    sprintf(mensagem, "Vidas: %d", pega_numero_de_vidas_do_bote(id));
  textout_ex(destino, font, mensagem, inicio_x, inicio_y, makecol(0,0,0), -1);
}

void imprime_pontuacao(int id, int inicio_y, int inicio_x, BITMAP *destino){
  sprintf(mensagem, "Pontos: %d", pega_pontuacao_do_bote(id));
  textout_ex(destino, font, mensagem, inicio_x, inicio_y, makecol(0,0,0), -1);
}

void imprime_nome(char *nome_do_jogador, int inicio_y, int inicio_x, BITMAP *destino){
  textout_ex(destino, font, nome_do_jogador, inicio_x, inicio_y, makecol(0,0,0), -1);
}

void imprime_numero_de_passageiros_a_bordo(int id, int inicio_y, int inicio_x, BITMAP *destino){
  sprintf(mensagem, "#Passageiros: %d", pega_numero_de_passageiros_a_bordo(id));
  textout_ex(destino, font, mensagem, inicio_x, inicio_y, makecol(0,0,0), -1);
}

void imprime_informacoes_do_bote(int id, char *nome_do_jogador, int inicio_y, int inicio_x, BITMAP *destino){
  imprime_nome(nome_do_jogador, inicio_y, inicio_x, destino);
  imprime_vida(id, inicio_y+25, inicio_x, destino);
  imprime_pontuacao(id, inicio_y+35, inicio_x, destino);
  imprime_numero_de_passageiros_a_bordo(id, inicio_y+45, inicio_x, destino);
}

void imprime_informacoes(BITMAP *destino){
  imprime_informacoes_do_bote(0, "Jogador 1", 630, 25, destino);
  imprime_informacoes_do_bote(1, "Jogador 2", 630, 895, destino);
}
