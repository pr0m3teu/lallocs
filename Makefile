CFLAGS=-Wall -Wextra -std=c11 
CC=clang

main: main.c lallocs.h
	$(CC) -o main $(CFLAGS) main.c
