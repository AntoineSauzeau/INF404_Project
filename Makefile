CC=g++
ARGS=-c -g

all: main

main.o: main.cpp
	$(CC) $(ARGS) main.cpp

lexeme.o: lexeme.cpp lexeme.hpp
	$(CC) $(ARGS) lexeme.cpp

parser.o: parser.cpp parser.hpp
	$(CC) $(ARGS) parser.cpp

object.o: object.cpp object.hpp
	$(CC) $(ARGS) object.cpp

button.o: button.cpp button.hpp object.hpp
	$(CC) $(ARGS) button.cpp

main: main.o lexeme.o parser.o button.o object.o
	$(CC) -o main main.o lexeme.o parser.o button.o object.o


clean:
	rm -r *.o main

