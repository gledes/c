#include <stdio.h>
#include <stdlib.h>


int execute(const char* cmdline, char* output, int maxsize)
{
	FILE* fp = popen(cmdline, "r");
	if (!fp)
	{
		return -1;
	}

	int size = 0;
	maxsize -= 1;

	while (!feof(fp))
	{
		int n = fread(output + size, 1, maxsize - size, fp);
		printf("n:%d\n", n);
		if (n <= 0)
		{
			break;
		}
		size +=n;
	}

	pclose(fp);
	output[size] = 0;
	return size;
}

int main()
{
	char buf[512];
	int n = execute("ifconfig", buf, 512);
	if (n > 0)
	{
		buf[n] = 0;
		printf("--------output----------------\n");
		printf("%s\n", buf);
	}
	printf("hello\n");
}