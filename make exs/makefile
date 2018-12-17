prog : main.o fonc.o
	gcc -o prog main.o fonc.o -lm
main.o : main.c fonc.o
	gcc -o main.o -c main.c
fonc.o : fonc.c fonc.h
	gcc -c fonc.c -o fonc.o
clean :
	rm *.o prog