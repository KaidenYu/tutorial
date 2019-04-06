#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>

void clobber(char*, int);

void printHi()
{
    printf("Hi!\n");

}


void printiH()
{
    printf("iH!\n");
}

char* buf;

int main(int argc, char** argv)
{
	printf("%p : this is main!\n",&main);
    char* x = alloca(8); //useless?
    buf = malloc(16);
    *(long*) buf = (long)&printHi;
    *(long*) (buf + 8) = (long)&printiH;
#if 0 // enable this cause infinite loop due to return to start of main function
    *(long*) (buf + 16) = (long)&main; 
#endif
    //*(long*) (buf + 8) = 0x0000000000400560;

    printf("before clobber\n");

    //clobber(buf, 24);
    clobber(buf, 16);
    //clobber(buf, 8);

    printf("after clobber\n");

    clobber(x, 8); //useless?
    return 0;
}