
CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LIBS=-lpthread
OBJS=second-threaded.o

second-threaded: $(OBJS)
	$(CC) -o second-threaded $(OBJS) $(LIBS)

clean:
	rm second-threaded $(OBJS)