CC=gcc
LD=ld
CFLAGS=-O0 -g -ldl


all: main tabort.so

objects: plugin.o main.o tabort.so uassembler.o

uassembler.o: uassembler.h uassembler.c

plugin.o: plugin.h plugin.c

main.o: plugin.h main.c
	$(CC) -c -o main.o main.c $(CFLAGS)

main: main.o plugin.o uassembler.o
	$(CC) -o main $^ $(CFLAGS)

tabort.o: plugin.h tabort.c
	$(CC) -o $@ -c tabort.c $(CFLAGS)
tabort_payload.o: plugin.h tabort_payload.S
	$(CC) -o $@ -c tabort_payload.S $(CFLAGS)
tabort.so: tabort.o tabort_payload.o
	$(LD) -o $@ -shared $^ $(FLAGS)
	
clean:
	rm -fr *.o *.so main
