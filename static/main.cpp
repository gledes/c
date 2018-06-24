#include <stdio.h>
#include "src/test1.h"
#include "src/test2.h"

int main(int argc, char *argv[])
{
	test1();
	test2();
	printf("Hello, world\n");
	
	return 0;
}
