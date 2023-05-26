CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: demo.out

run: demo.out
	./demo.out

clean:
	rm -f ./build/*
	rm -f demo.out

demo.out: build/main.o
	$(CC) $^ -o $@ $(CFLAGS)

build/main.o: src/main.cpp
	$(CC) -c $^ -o $@
