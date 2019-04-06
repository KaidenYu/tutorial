CC = gcc

PROG = memory_reference_bug
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
	./$(PROG) 0
	./$(PROG) 1
	./$(PROG) 2
	./$(PROG) 3
	./$(PROG) 4
	./$(PROG) 5
	./$(PROG) 6
	./$(PROG) 7
	./$(PROG) 8
	./$(PROG) 9
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



