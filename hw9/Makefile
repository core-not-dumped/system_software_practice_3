CC = g++
CFLAGS = -O2
TARGET = main.out
OBJS = poly.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main.out

