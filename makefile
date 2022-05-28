main.o : main.c 
	gcc -c main.c


color.o : color.c 
	gcc -c color.c 

color.gch : color.h
	gcc -c color.h

OctNode.o : OctNode.c
	gcc -c OctNode.c

OctNode.gch : OctNode.h
	gcc -c OctNode.h

output : main.o color.o OctNode.o
	gcc main.o color.o OctNode.o -o output

