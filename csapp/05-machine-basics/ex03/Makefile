CC = gcc

OBJ = sum.o
SRC = sum.c
ASRC = sum.s

define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef

.PHONY:all
all:objdump cat_asm

objdump:$(OBJ)
	$(call colorecho,"### objdump" $(OBJ) "###")
	objdump -Slz $(OBJ)
	@echo

.PHONY:cat_asm
cat_asm:$(ASRC)
	$(call colorecho,"### cat" $(ASRC) "###")
	cat $(ASRC)
	@echo

$(OBJ):$(ASRC)
	$(call colorecho,"### generating" $(OBJ) "###")
	$(CC) -c $(SRC)
	@echo

$(ASRC):$(SRC)
	$(call colorecho,"### generating" $(ASRC) "###")
	$(CC) -Og -S $(SRC)
	@echo

.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f *.o *.s
	@echo