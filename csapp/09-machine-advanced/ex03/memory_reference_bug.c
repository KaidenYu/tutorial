#include <stdio.h>

typedef struct {
	int a[2];
	double d;
} struct_t;

double fun(int i) {
	volatile struct_t s;
	s.d = 3.14;
	s.a[i] = 1073741824; /* Possibly out of bounds */
	return s.d;
}

int main(int argc, char** argv)
{
	int input = atoi(argv[1]);
	//printf("input=%d\n",input);

	double result = fun(input);
	printf("fun(%d)=%1.14f\n",input,result);

	return 0;
}