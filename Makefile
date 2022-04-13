CC=g++
ARGS=-c -g
LIBS=-lsfml-graphics

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

ast_node.o: ast_node.cpp ast_node.hpp
	$(CC) $(ARGS) ast_node.cpp

window.o: window.cpp window.hpp
	$(CC) $(ARGS) window.cpp

interface.o: interface.cpp interface.hpp
	$(CC) $(ARGS) interface.cpp

main: main.o lexeme.o parser.o button.o object.o ast_node.o window.o interface.o
	$(CC) -o main main.o lexeme.o parser.o button.o object.o ast_node.o window.o interface.o $(LIBS)


clean:
	rm -r *.o main

