CC=gcc
CFLAGS=-m32 -g
CLIB=-I./include -L./lib -lhardware
EXEC=dmps frmt


all: $(EXEC)

dmps: dmps.o Driver.o
	$(CC) -o $@ $^ $(CFLAGS) $(CLIB)

frmt: frmt.o Driver.o
	$(CC) -o $@ $^ $(CFLAGS) $(CLIB)

Driver.o: Driver.c Driver.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CLIB)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean realclean

clean:
	rm -rf *~ *.o

realclean:
	make clean
	rm -rf $(EXEC)
