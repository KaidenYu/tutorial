CC = gcc


PROG = prog
CSRC = $(wildcard *.c)
OBJS = $(CSRC:%.c=%.o) # no space between ":"" and "%"

define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef

.PHONY:all
all:$(PROG) objdump

.PHONY:objdump
objdump:
	$(call colorecho,"### objdump main.o ###")
	objdump -r -d main.o > objdump_main.txt
	$(call colorecho,"### objdump prog ###")
	objdump -dx prog > objdump_prog.txt
	@echo

$(PROG):$(OBJS) #can't replace $(OBJS) with %.o in any case?
	$(call colorecho,"### generating" $(PROG) "###")
	$(CC) $(OBJS) -Og -o $(PROG) 
	@echo 

%.o:%.c
	$(call colorecho,"### generating" $@ "###" 	)
	$(CC) -c -Og $^ -o $@
	@echo 



.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f $(PROG) *.o *.txt
	@echo