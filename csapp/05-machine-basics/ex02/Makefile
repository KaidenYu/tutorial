CC = gcc

OBJ = arith.o
SRC = arith.c

.PHONY:all
all:objdump

objdump:$(OBJ)
	@echo "### objdump" $(OBJ) "###"
	objdump -Slz $(OBJ)
	@echo

$(OBJ):$(SRC)
	@echo "### generating" $(OBJ) "###"
	$(CC) -Og -c $(SRC)
	@echo

.PHONY:clean
clean:
	rm -f *.o