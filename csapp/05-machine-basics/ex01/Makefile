CC = gcc

PROG = swap 
SRC = callswap.c swap.s

.PHONY:all
all:$(PROG)

$(PROG):$(SRC)
	$(CC) $(SRC) -Og -o $(PROG)

.PHONY:clean
clean:
	rm -f *.o $(PROG)