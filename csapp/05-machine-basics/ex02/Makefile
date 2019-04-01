CC = gcc

OBJ = arith.o
SRC = arith.c

define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef

.PHONY:all
all:objdump

.PHONY:objdump
objdump:$(OBJ)
	$(call colorecho,"### objdump" $(OBJ) "###")
	objdump -Slz $(OBJ)
	@echo

$(OBJ):$(SRC)
	$(call colorecho,"### generating" $(OBJ) "###")
	$(CC) -Og -c $(SRC)
	@echo

.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f *.o
	@echo