#include <stdio.h>

int recurse(int x) {
	int a[2<<15]; /* 2~17 = 128 KiB */
	printf("x = %d. a at %p\n", x, a);
	a[0] = (2<<13)-1;
	a[a[0]] = x-1;
	if (a[a[0]] == 0)
		return -1;
	return recurse(a[a[0]]) - 1;
}

int main(int argc, char** argv)
{
	int input = atoi(argv[1]);
	//printf("input=%d\n",input);

	recurse(input);

	return 0;
}