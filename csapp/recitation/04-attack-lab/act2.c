#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <sys/mman.h>
#include <stdint.h>

//#define DUMMY_B

void clobber(char*, int);
const char hiStr[] = "Hi\n";

int main(int argc, char** argv)
{
    //alloc is different from malloc. malloc in heap ; alloc in stack
    char* dummy_a = alloca(32);
    char* x = alloca(32); //char x[32]; cannot replace pointer with array
#ifdef DUMMY_B //enable this the trick won't work. cause the inserted code will be written into dummy_b
    char* dummy_b = alloca(32);
#endif

    
    unsigned char* m = malloc(128);
    
    puts("Activity 2!");
    if (m == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
        return -1;
    }
    if (mprotect((void*)(((uint64_t)x) & (~0xfff)), 4096, PROT_READ | PROT_WRITE | PROT_EXEC) == -1)
    {
        perror("MPROTECT");
        free(m);
        return -1;
    }


    printf("%p : dummy_a\n",dummy_a);
    printf("%p : x\n",x);
#ifdef DUMMY_B
    printf("%p : dummy_b\n",dummy_b);
#endif
    printf("%p : m\n",m);
    printf("%p : hiStr\n",hiStr);
    printf("%p : puts()\n",puts);
    printf("%p : exit()\n",exit);


    *(uint64_t*) m = (uint64_t)(x);
    m[8] = 0xbf;
    *(uint32_t*) (m + 9) = (unsigned int)(uint64_t) hiStr;

#if 0
    *(uint32_t*) (m + 13) = 0x4022e0be; //puts function
#else
    *(uint32_t*) (m + 14) = (unsigned int)(uint64_t)puts;
    *(unsigned char*) (m + 13) = 0xbe;
    printf("m[13]=%x\n",*(uint32_t*)(m+13));
#endif

    *(uint32_t*) (m + 18) = 0xd6ff;

#if 0
    *(uint32_t*) (m + 20) = 0x4011a0be; //exit function
#else
    *(uint32_t*) (m + 21) = (unsigned int)(uint64_t)exit; //exit function
    *(unsigned char*) (m + 20) = 0xbe;
    printf("m[20]=%x\n",*(uint32_t*)(m+20));
#endif

    *(uint32_t*) (m + 25) = 0xd6ff;

    /*
    for(int i=0;i<32;i++)
        printf("*(x+%d)=%x\n",i,*(x+i));
    */

    clobber(m, 32);

    
    
    return 0;
}