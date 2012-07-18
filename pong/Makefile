CC=g++
CFLAGS=-g -ansi -pedantic -Wall
LDFLAGS=-lSDL -lSDLmain -lSDL_image
IFLAGS=-I/usr/include/SDL

all: Pong.o Event.o Pong_Events.o FPS.o Surface.o Ball.o Bar.o AI.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o Pong 

Pong.o: Define.h Pong.h Pong.cpp Pong_Events.cpp
	$(CC) $(CFLAGS) -c Pong.cpp Pong_Events.cpp

Event.o: Event.h Event.cpp
	$(CC) $(CFLAGS) -c Event.cpp

FPS.o: FPS.h FPS.cpp
	$(CC) $(CFLAGS) -c FPS.cpp

Surface.o: Surface.h Surface.cpp
	$(CC) $(CFLAGS) -c Surface.cpp

Ball.o: Ball.h Define.h FPS.h Ball.cpp
	$(CC) $(CFLAGS) -c Ball.cpp

Bar.o: Bar.h Bar.cpp
	$(CC) $(CFLAGS) -c Bar.cpp

AI.o: AI.h AI.cpp
	$(CC) $(CFLAGS) -c AI.cpp

.PHONY:
clean:
	rm -f Pong *.o *.g *.gch
