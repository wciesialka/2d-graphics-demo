CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

run: demo
	./demo

clean:
	rm -f ./build/*
	rm -f demo

demo: build/main.o
	$(CC) $^ -o $@ $(CFLAGS)

build/main.o: src/main.cpp
	$(CC) -c $^ -o $@

