CC = g++
all: hello
hello: hello.o
	${CC} -o hello hello.o
hello.o: hello.cpp
	${CC} -c -g hello.cpp
clean:
	rm hello.o hello
