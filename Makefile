# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Madeline Bumpus>

list: list.c main.c
	gcc list.c main.c -o listexe