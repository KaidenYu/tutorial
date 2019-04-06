CC = gcc

PROG = vulnerable_buffer_code
SRC = $(PROG).c


define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef

.PHONY:all
all:objdump run

.PHONY:objdump
objdump:$(PROG)
	$(call colorecho,"### objdump" $(PROG) "###")
	objdump -Slz $(PROG)
	@echo

.PHONY:run
run:$(PROG)
	$(call colorecho,"### run" $(PROG) "###")
	$(call colorecho,"### input something ###")
	./$(PROG)
	@echo


$(PROG):$(SRC)
	$(call colorecho,"### generating" $(PROG) "###")
	$(CC) $(SRC) -Og -fno-stack-protector -o $(PROG)
	@echo

.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f *.o $(PROG)
	@echo 



