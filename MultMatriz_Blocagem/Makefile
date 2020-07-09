all: prog

run: prog
	./prog

perf: prog
	sudo perf stat -e L1-dcache-load-misses,L1-dcache-store-misses ./prog

valgrind: prog
	gcc -o prog -g -Wall -ggdb3 MultiplicaMatriz_Blocagem.o -g
	valgrind -v --leak-check=full --show-leak-kinds=all ./prog
	
prog: MultiplicaMatriz_Blocagem.o
	gcc -o prog MultiplicaMatriz_Blocagem.o -g

MultiplicaMatriz_Blocagem.o: MultiplicaMatriz_Blocagem.c
	gcc -c MultiplicaMatriz_Blocagem.c

clean: 
	rm -rf *o prog
