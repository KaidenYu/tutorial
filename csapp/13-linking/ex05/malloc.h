#ifndef _MALLOC_H
#define _MALLOC_H

#define malloc(size) mymalloc(size)
#define free(ptr) myfree(ptr)

void *mymalloc(size_t size);
void myfree(void *ptr);

#endif