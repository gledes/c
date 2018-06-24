#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 

int test_write()
{
	printf("Hello, world\n");
	FILE* fp = fopen("aaa.txt", "wb");
	if(!fp)
	{
		printf("failed to open file\n");
		return -1;
	}
	

	char buf[] = "helloworld\n";
	fwrite(buf, 1, strlen(buf), fp);
	fclose(fp);
	return 0;
}

int test_read()
{
	int fd = open("aaa.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	if(fd < 0)
	{
		printf("fail to open\n");
		return -1;
	}
	
	char data[12];
	int n = read(fd, data, 12);
	if(n > 0)
	{
		printf("n:%d\n", n);
		//data[n] = '\0';
		//printf("data[15]:%d\n", data[15]);
		printf("read:%s\n", data);
	}
	close(fd);
}

int main()
{
	int flag;
	printf("please intput 1 or 2\n");
	scanf("%d", &flag);
	if (flag == 1)
	{
		test_write();
	}

	if (flag == 2)
	{
		test_read();
	}
}

