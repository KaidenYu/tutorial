#include <stdio.h>
#include <stdlib.h>

void swap(long *one, long *two);
int main(void)
{
	long a=1;
	long b=2;
	printf("before swap a=%ld,b=%ld\n",a,b);
	swap(&a,&b);
	printf("after swap a=%ld,b=%ld\n",a,b);
	return 123;
}