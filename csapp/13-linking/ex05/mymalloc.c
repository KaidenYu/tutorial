#ifdef COMPILETIME
#include <stdio.h>
#include <malloc.h>
/* malloc wrapper function */
void *mymalloc(size_t size)
{
	void *ptr = malloc(size);
	printf("COMPILETIME malloc(%d)=%p\n", (int)size, ptr);
	return ptr;
}
/* free wrapper function */
void myfree(void *ptr)
{
	free(ptr);
	printf("COMPILETIME free(%p)\n", ptr);
}
#endif

#ifdef LINKTIME
#include <stdio.h>
void *__real_malloc(size_t size);
void __real_free(void *ptr);
/* malloc wrapper function */
void *__wrap_malloc(size_t size)
{
	void *ptr = __real_malloc(size); /* Call libc malloc */
	printf("LINKTIME malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}
/* free wrapper function */
void __wrap_free(void *ptr)
{
	__real_free(ptr); /* Call libc free */
	printf("LINKTIME free(%p)\n", ptr);
}
#endif


#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

/* malloc wrapper function */
void *malloc(size_t size)
{
	
	void *(*mallocp)(size_t size);
	char *error;
	mallocp = dlsym(RTLD_NEXT, "malloc"); /* Get addr of libc malloc */
	if ((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(1);
	}
	char *ptr = mallocp(size); /* Call libc malloc */
	
	#if 0
	printf("RUNTIME malloc(%d) = %p\n", (int)size, ptr);
	#else
	char buf[256];
	sprintf(buf,"echo RUNTIME malloc size:%d = %p", (int)size, ptr);
	system(buf);
	#endif
	/*********************************************************
	//
	// the printf above casuse segmentation fault !!!!!!!
	// use echo instead
	//
	**********************************************************/
	return ptr;
	
}
/* free wrapper function */
void free(void *ptr)
{
	
	void (*freep)(void *) = NULL;
	char *error;
	if (!ptr)
		return;
	freep = dlsym(RTLD_NEXT, "free"); /* Get address of libc free */
	if ((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(1);
	}
	freep(ptr); /* Call libc free */
	printf("RUNTIME free(%p)\n", ptr);
	
}
#endif