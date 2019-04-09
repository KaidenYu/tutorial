CC = gcc


define colorecho
	@tput setaf 1
	@echo $1
	@tput sgr0
endef



.PHONY:runc
runc:intc
	$(call colorecho,"### executing ./intc 10 100 1000 ###")
	./intc 10 100 1000
	@echo
	

intc:int.c mymalloc.c
	$(call colorecho,"### generating intc ###")
	$(CC) -Wall -DCOMPILETIME -c mymalloc.c
	$(CC) -Wall -I. -o intc int.c mymalloc.o
	@echo


.PHONY:runl
runl:intl
	$(call colorecho,"### executing ./intl 10 100 1000 ###")
	./intl 10 100 1000
	@echo
	

intl:int.c mymalloc.c
	$(call colorecho,"### generating intl ###")
	gcc -Wall -DLINKTIME -c mymalloc.c
	gcc -Wall -c int.c
	gcc -Wall -Wl,--wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o
	@echo 



.PHONY:runr
runr:intr
	$(call colorecho,"### executing intr with shell sciprt runtime_malloc.sh ###")
	sh runtime_malloc.sh
	@echo
	

intr:int.c mymalloc.c
	$(call colorecho,"### generating intc ###")
	gcc -Wall -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl
	gcc -Wall -o intr int.c
	@echo 


.PHONY:clean
clean:
	$(call colorecho,"### clean ###")
	rm -f intc intl intr *.o *.so
	@echo