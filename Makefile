CC = g++
CFLAGS = -lsfml-graphics

run: demo
	./demo

clean:
	rm -f ./*.o
	rm -f demo

demo: src/main.cpp
	$(CC) $(CFLAGS) $^ -o $@