all: a.out

a.out: main.cpp shapes.h
	g++ -std=c++11 main.cpp

test: a.out
	./a.out rectangle 2 3

clean:
	rm a.out