CC = gcc

PROG = runaway_stack_example
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
	./$(PROG) 48
	@echo


$(PROG):$(SRC)
	$(call colorecho,"### objdump" $(PROG) "###")
	$(CC) $(SRC) -Og -o $(PROG)
	@echo

.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f *.o $(PROG)
	@echo 



