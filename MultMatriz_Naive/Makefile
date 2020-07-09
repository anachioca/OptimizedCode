all: prog

run: prog
	./prog

perf: prog
	sudo perf stat -e L1-dcache-load-misses,L1-dcache-store-misses ./prog

valgrind: prog
	gcc -o prog -g -Wall -ggdb3 MultiplicaMatriz_Naive.o -g
	valgrind -v --leak-check=full --show-leak-kinds=all ./prog
	
prog: MultiplicaMatriz_Naive.o
	gcc -o prog MultiplicaMatriz_Naive.o -g

MultiplicaMatriz_Naive.o: MultiplicaMatriz_Naive.c
	gcc -c MultiplicaMatriz_Naive.c

clean: 
	rm -rf *o prog
