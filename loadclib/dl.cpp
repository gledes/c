#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

int main()
{
	printf("Hello, world dl\n");
	void* lib = dlopen("build/libexample.so", RTLD_NOW);
	if (!lib)
	{
		printf("failed to load library!\n");
		return -1;
	}

	typedef int (*SO_FUNCTION)(int, int);

	SO_FUNCTION f = (SO_FUNCTION)dlsym(lib, "example");
	if (!f)
	{
		printf("cannot find the symbol in library!\n");
		return -1;
	}

	f(1, 2);

	dlclose(lib);
	return 0;
}
