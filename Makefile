CC=g++
ARGS=-c -g -std=c++11
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lpthread 

all: main

main.o: main.cpp
	$(CC) $(ARGS) main.cpp

lexeme.o: lexeme.cpp lexeme.hpp
	$(CC) $(ARGS) lexeme.cpp

parser.o: parser.cpp parser.hpp
	$(CC) $(ARGS) parser.cpp

object.o: object.cpp object.hpp
	$(CC) $(ARGS) object.cpp

text.o: text.cpp text.hpp
	$(CC) $(ARGS) text.cpp

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

animation.o: animation.cpp animation.hpp
	$(CC) $(ARGS) animation.cpp

animation_handler.o: animation_handler.cpp animation_handler.hpp
	$(CC) $(ARGS) animation_handler.cpp

image.o: image.cpp image.hpp
	$(CC) $(ARGS) image.cpp

main: main.o lexeme.o parser.o text.o object.o ast_node.o window.o interface.o rect.o circle.o triangle.o animation.o animation_handler.o image.o
	$(CC) -o main $^ $(LIBS)


clean:
	rm -r *.o main

