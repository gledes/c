#include <stdio.h>
#include "example.h"

void Object::test()
{
	printf("Object::test, id:%d\n", id);
}

int example(int a, int b)
{
	printf("a:%d b:%d hello, world\n", a, b);
	//printf("hello");
	
	return 0;
}
