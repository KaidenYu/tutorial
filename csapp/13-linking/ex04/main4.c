#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];
int main(int argc, char** argv)
{
	void *handle;
	void (*addvec_fptr)(int *, int *, int *, int);
	void (*multvec_fptr)(int *, int *, int *, int);
	void (*addsqvec_fptr)(int *, int *, int *, int);

	char *error;

	/* Dynamically load the shared library that contains addvec() */
	handle = dlopen("./libvector.so", RTLD_LAZY); // the "./" is necessary
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	/* Get a pointer to the addvec() function we just loaded */
	addvec_fptr = dlsym(handle, "addvec");
	multvec_fptr = dlsym(handle, "multvec");
	addsqvec_fptr = dlsym(handle, "addsqvec");

	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	/* Now we can call addvec() just like any other function */

	addvec_fptr(x, y, z, 2);
	//multvec_fptr(x, y, z, 2);
	//addsqvec_fptr(x, y, z, 2);
	
	printf("z = [%d %d]\n", z[0], z[1]);

	/* Unload the shared library */
	if (dlclose(handle) < 0) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	return 0;
}