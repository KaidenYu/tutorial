CC = gcc


PROG = prog3
SRC = main3.c
OBJS = main3.o
LIB_SRC = addvec.c multvec.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB = libvector.so
CFLAGS = -Og -L. -l$(subst .so,,$(subst lib,,$(LIB)))

export LD_LIBRARY_PATH=$(shell pwd):$LD_LIBRARY_PATH;

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
	$(call colorecho," !!! export in makefile won't change its parent's environment !!!")
	$(call colorecho," !!! export yourself if you want to execute" $(PROG) "thru command line !!!")
	$(call colorecho," !!! or you can simply make a shell script to do that !!!")


.PHONY:objdump
objdump:
	$(call colorecho,"### objdump main.o ###")
	objdump -r -d main3.o > objdump_main3.txt
	$(call colorecho,"### objdump prog ###")
	objdump -dx prog3 > objdump_prog3.txt
	@echo

$(PROG):$(OBJS) $(LIB) #can't replace $(OBJS) with %.o in any case?
	$(call colorecho,"### generating" $(PROG) "###")
	$(CC) $(OBJS) $(CFLAGS) -o $(PROG) 
	@echo 

$(LIB):$(LIB_OBJ)
	$(call colorecho,"### generating" $(LIB) "###")
	gcc -shared -o $(LIB) $(LIB_OBJ) -fpic
	@echo

%.o:%.c
	$(call colorecho,"### generating" $@ "###" 	)
	$(CC) -c -Og $^ -o $@
	@echo 



.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f $(PROG) *.o *.txt *.so
	@echo