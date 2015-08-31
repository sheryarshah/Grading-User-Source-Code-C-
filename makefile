program: main.o Program_results.o  
	gcc -o program main.o Program_results.o 
main.o: main.c header.h
	gcc -c main.c
Program_results.o: Program_results.c header.h
	gcc -c Program_results.c 
