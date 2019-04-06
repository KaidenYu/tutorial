CC = gcc
INPUT = act1.c act2.c act3.c support.s
PROJECT = act1 act2 act3
CFLAGS = --std=c99 -g -Og -static

all: $(PROJECT) objdump

.PHONY:objdump
objdump:
	objdump -d act3 > obj3
	objdump -d act2 > obj2
	objdump -d act1 > obj1
	objdump -d kaiden_tool.o > obj_kaiden_tool

$(PROJECT) :  $(INPUT)
	$(CC) $(CFLAGS) act1.c support.s -o act1
	$(CC) $(CFLAGS) act2.c support.s -o act2
	$(CC) $(CFLAGS) act3.c support.s -o act3
	$(CC) -Og -c kaiden_tool.s -o kaiden_tool.o

clean:
	rm -f $(PROJECT) obj*
