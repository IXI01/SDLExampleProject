##################################################
## MAKEFILE for Tutorial
##################################################

CC=g++
CFLAGS=-g -ansi -pedantic -Wall
LDFLAGS=-lSDL -lSDLmain -lSDL_image
IFLAGS=-I/usr/include/SDL

all: CApp.o CApp_OnCleanup.o CApp_OnEvent.o CApp_OnRender.o CApp_OnInit.o CApp_OnLoop.o CSurface.o CEvent.o CAnimation.o CEntity.o CMap.o CCamera.o CArea.o CTile.o CFPS.o CPlayer.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o CApp 

CApp.o: CApp.h CEvent.h CSurface.h CAnimation.h CEntity.h CMap.h CArea.h CCamera.h CTile.h Define.h CFPS.h CPlayer.h CApp.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CSurface.cpp CEvent.cpp CAnimation.cpp CEntity.cpp CArea.cpp CCamera.cpp CMap.cpp CTile.cpp CPlayer.cpp CFPS.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^
.PHONY:
clean:
	rm -f CApp *.o *.g *.gch

