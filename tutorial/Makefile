##################################################
## MAKEFILE for Tutorial
##################################################

CC=g++
CFLAGS=-g -ansi -pedantic -Wall
LDFLAGS=-lSDL -lSDLmain
IFLAGS=-I/usr/include/SDL

all: CApp.o CApp_OnCleanup.o CApp_OnEvent.o CApp_OnRender.o CApp_OnInit.o CApp_OnLoop.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o CApp 

CApp.o: CApp.h CApp.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $^

.PHONY:
clean:
	rm -f CApp *.o *.g

