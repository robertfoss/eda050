CC		= gcc

CFLAGS		= -g -Wall -pedantic -C99

LDFLAGS		= -g

OUT		= sh

OBJS		= sh.o list.o

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT)
	./sh

clean:
	rm -f *.o sh core out
