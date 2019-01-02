#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
	const char *pathname = "hello.txt";
	int fd = open(pathname, 0666 | O_RDWR);

	size_t length = 20*sizeof(char);
	char *addr    = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	scanf("%s", addr);
	
	char buf[20];
	int i;
	for(i = 0; i < 20; ++i)
		buf[i] = *(addr +i);

	printf("%s\n", buf);
	
	read(fd, buf, length);
	printf("%s\n", buf);
	
	munmap(addr, length);
	close(fd);
	
	return 0;
}
