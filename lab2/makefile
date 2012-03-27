CC		= gcc

CFLAGS		= -g -Wall -pedantic -g

LDFLAGS		= -g

all: 02 05 10

02: 02-crash.o
	$(CC) $(LDFLAGS) 02-crash.o  -o 02

05: 05-loop.o
	$(CC) $(LDFLAGS) 05-loop.o -o 05

10: 10-sigloop.o
	$(CC) $(LDFLAGS) 10-sigloop.o -o 10

clean:
	rm -f *.o
