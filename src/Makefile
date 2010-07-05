CFLAGS = -Wall -pedantic -ansi -O2 -g -ggdb3 -lalleg-4.2.2 
dependencies = main.o estado_inicial.o imprime_estado_atual.o jogo.o movimenta_elementos.o naufrago.o visualizacao_grafica.o coral.o colisoes.o asimov.o bote.o imprime_informacoes.o teclas.o
objects = ../lib/main.o ../lib/estado_inicial.o ../lib/imprime_estado_atual.o ../lib/jogo.o ../lib/movimenta_elementos.o ../lib/naufrago.o ../lib/visualizacao_grafica.o ../lib/coral.o ../lib/colisoes.o ../lib/asimov.o ../lib/bote.o ../lib/imprime_informacoes.o ../lib/teclas.o

all: ../lib ${dependencies}
	clear
	gcc ${CFLAGS} -o exe ${objects}

main.o: ../lib main.c
	gcc ${CFLAGS} -c main.c -o ../lib/main.o

estado_inicial.o: ../lib estado_inicial.c estado_inicial.h
	gcc ${CFLAGS} -c estado_inicial.c -o ../lib/estado_inicial.o

imprime_estado_atual.o: ../lib imprime_estado_atual.c imprime_estado_atual.h
	gcc ${CFLAGS} -c imprime_estado_atual.c -o ../lib/imprime_estado_atual.o

jogo.o: ../lib jogo.c jogo.h
	gcc ${CFLAGS} -c jogo.c -o ../lib/jogo.o

movimenta_elementos.o: ../lib movimenta_elementos.c movimenta_elementos.h
	gcc ${CFLAGS} -c movimenta_elementos.c -o ../lib/movimenta_elementos.o

naufrago.o: ../lib naufrago.c naufrago.h
	gcc ${CFLAGS} -c naufrago.c -o ../lib/naufrago.o

visualizacao_grafica.o: ../lib visualizacao_grafica.c visualizacao_grafica.h
	gcc ${CFLAGS} -c visualizacao_grafica.c -o ../lib/visualizacao_grafica.o

coral.o: ../lib coral.c coral.h
	gcc ${CFLAGS} -c coral.c -o ../lib/coral.o

colisoes.o: ../lib colisoes.c colisoes.h
	gcc ${CFLAGS} -c colisoes.c -o ../lib/colisoes.o

asimov.o: ../lib asimov.c asimov.h
	gcc ${CFLAGS} -c asimov.c -o ../lib/asimov.o

bote.o: ../lib bote.c bote.h
	gcc ${CFLAGS} -c bote.c -o ../lib/bote.o 

imprime_informacoes.o: ../lib imprime_informacoes.c imprime_informacoes.h
	gcc ${CFLAGS} -c imprime_informacoes.c -o ../lib/imprime_informacoes.o 

teclas.o: ../lib teclas.c teclas.h
	gcc ${CFLAGS} -c teclas.c -o ../lib/teclas.o 

../doc/Relatorio.pdf: ../doc/src/Relatorio.tex
	pdflatex ../doc/src/Relatorio.tex
	pdflatex ../doc/src/Relatorio.tex
	pdflatex ../doc/src/Relatorio.tex
	pdflatex ../doc/src/Relatorio.tex
	rm -f Relatorio.dvi Relatorio.aux Relatorio.log Relatorio.toc
	mv Relatorio.pdf doc/

../doc: ../doc/Relatorio.pdf

testes: lib ${dependencies_for_tests} src/minunit.c
	gcc ${CFLAGS} src/minunit.c ${objects_for_tests} -o teste
	clear	
	./teste


../lib: 
	mkdir ../lib

clean:
	rm -rf exe test ../lib ../doc/Relatorio.pdf
