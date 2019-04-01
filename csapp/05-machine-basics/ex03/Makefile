CC = gcc

OBJ = sum.o
SRC = sum.c
ASRC = sum.s

.PHONY:all
all:objdump

objdump:$(OBJ)
	@echo "### objdump" $(OBJ) "###"
	objdump -Slz $(OBJ)
	@echo

.PHONY:cat_asm
cat_asm:$(ASRC)
	@echo "### cat" $(ASRC) "###"
	cat $(ASRC)
	@echo

$(OBJ):$(ASRC)
	@echo "### generating" $(OBJ) "###"
	$(CC) -c $(SRC)
	@echo

$(ASRC):$(SRC)
	@echo "### generating" $(ASRC) "###"
	$(CC) -Og -S $(SRC)
	@echo

.PHONY:clean
clean:
	rm -f *.o *.s