CC = gcc


PROG = prog4
SRC = main4.c
OBJS = main4.o
LIB_SRC = addvec.c multvec.c
LIB_OBJ = $(LIB_SRC:%.c=%.o)
LIB = libvector.so
CFLAGS = -Og -ldl
#-L. -l$(subst .so,,$(subst lib,,$(LIB)))

#export LD_LIBRARY_PATH=$(shell pwd):$LD_LIBRARY_PATH;

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
	$(call colorecho," !!! doesn't need to set LD_LIBRARY_PATH using run-time dynamic linking !!!")
	@echo
	


.PHONY:objdump
objdump:
	$(call colorecho,"### objdump main.o ###")
	objdump -r -d main4.o > objdump_main4.txt
	$(call colorecho,"### objdump prog ###")
	objdump -dx prog4 > objdump_prog4.txt
	@echo

$(PROG):$(OBJS) $(LIB) #can't replace $(OBJS) with %.o in any case?
	$(call colorecho,"### generating" $(PROG) "###")
	$(CC) $(OBJS) $(CFLAGS) -o $(PROG) 
	$(call colorecho," !!! need to add -ldl to use libdll.so !!!")
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