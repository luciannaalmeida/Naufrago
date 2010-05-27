CFLAGS = -Wall -pedantic -ansi -O2 -g  -lalleg-4.2.2 
dependencies = main.o estado_inicial.o imprime_estado_atual.o jogo.o movimenta_elementos.o naufrago.o animacao.o gera_animacao.o
objects = lib/main.o lib/estado_inicial.o lib/imprime_estado_atual.o lib/jogo.o lib/movimenta_elementos.o lib/naufrago.o lib/animacao.o lib/gera_animacao.o

all: lib ${dependencies}
	clear
	gcc ${CFLAGS} -o ep2 ${objects}

main.o: lib src/main.c
	gcc ${CFLAGS} -c src/main.c -o lib/main.o

estado_inicial.o: lib src/estado_inicial.c src/estado_inicial.h
	gcc ${CFLAGS} -c src/estado_inicial.c -o lib/estado_inicial.o

imprime_estado_atual.o: lib src/imprime_estado_atual.c src/imprime_estado_atual.h
	gcc ${CFLAGS} -c src/imprime_estado_atual.c -o lib/imprime_estado_atual.o

jogo.o: lib src/jogo.c src/jogo.h
	gcc ${CFLAGS} -c src/jogo.c -o lib/jogo.o

movimenta_elementos.o: lib src/movimenta_elementos.c src/movimenta_elementos.h
	gcc ${CFLAGS} -c src/movimenta_elementos.c -o lib/movimenta_elementos.o

naufrago.o: lib src/naufrago.c src/naufrago.h
	gcc ${CFLAGS} -c src/naufrago.c -o lib/naufrago.o

animacao.o: lib src/animacao.c src/animacao.h
	gcc ${CFLAGS} -c src/animacao.c -o lib/animacao.o
	
gera_animacao.o: lib src/gera_animacao.c src/gera_animacao.h
	gcc ${CFLAGS} -c src/gera_animacao.c -o lib/gera_animacao.o

testes: estado_inicial.o imprime_estado_atual.o jogo.o movimenta_elementos.o naufrago.o src/minunit.c
	gcc ${CFLAGS} src/minunit.c lib/estado_inicial.o lib/imprime_estado_atual.o lib/jogo.o lib/movimenta_elementos.o lib/naufrago.o -o teste
	clear	
	./teste

lib: 
	mkdir lib

clean:
	rm -rf ep2 lib
