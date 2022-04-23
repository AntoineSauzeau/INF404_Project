CC=g++
ARGS=-c -g
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

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

rect.o: rect.cpp rect.hpp
	$(CC) $(ARGS) rect.cpp

circle.o: circle.cpp circle.hpp
	$(CC) $(ARGS) circle.cpp

triangle.o: triangle.cpp triangle.hpp
	$(CC) $(ARGS) triangle.cpp

main: main.o lexeme.o parser.o button.o object.o ast_node.o window.o interface.o rect.o circle.o triangle.o
	$(CC) -o main $^ $(LIBS)


clean:
	rm -r *.o main

