CC = gcc
CFLAGS = -o pi
LDFLAGS = -lgmp

OBJS = pi.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	rm $(OBJS) pi