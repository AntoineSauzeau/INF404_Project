CC=g++
ARGS=-c -g

all: main

main.o: main.cpp
	$(CC) $(ARGS) main.cpp

lexeme.o: lexeme.cpp lexeme.hpp
	$(CC) $(ARGS) lexeme.cpp

parser.o: parser.cpp parser.hpp
	$(CC) $(ARGS) parser.cpp

main: main.o lexeme.o parser.o
	$(CC) -o main main.o lexeme.o parser.o


clean:
	rm -r *.o main

