CC = gcc


PROG = prog2
SRC = main2.c
OBJS = main2.o
LIB_SRC = addvec.c multvec.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB = libvector.a
CFLAGS = -Og -L. -l$(subst .a,,$(subst lib,,$(LIB)))


define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef

.PHONY:all
all:$(PROG) objdump run

.PHONY:run
run:
	$(call colorecho,"### executing" $(PROG) "###")
	./$(PROG)
	@echo

.PHONY:objdump
objdump:
	$(call colorecho,"### objdump main.o ###")
	objdump -r -d main2.o > objdump_main2.txt
	$(call colorecho,"### objdump prog ###")
	objdump -dx prog2 > objdump_prog2.txt
	@echo

$(PROG):$(OBJS) $(LIB) #can't replace $(OBJS) with %.o in any case?
	$(call colorecho,"### generating" $(PROG) "###")
	$(CC) $(OBJS) $(CFLAGS) -o $(PROG) 
	@echo 

$(LIB):$(LIB_OBJ)
	$(call colorecho,"### generating" $(LIB) "###")
	ar rs $(LIB) $(LIB_OBJ)
	@echo

%.o:%.c
	$(call colorecho,"### generating" $@ "###" 	)
	$(CC) -c -Og $^ -o $@
	@echo 



.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f $(PROG) *.o *.txt *.a
	@echo