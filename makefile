main.o : main.c 
	gcc -c main.c

color.o : color.c 
	gcc -c color.c 

color.gch : color.h
	gcc -c color.h

output : main.o color.o 
	gcc main.o color.o -o output