#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void PrintFile(char *pathname)
{
	int fd  = open(pathname, 0666 | O_RDONLY);
	if(fd == -1)
		return;
	
	int end   = lseek(fd, 0, SEEK_END);
	int start = lseek(fd, 0, SEEK_SET);
	if((end == -1) || (start == -1))
		return;
	
	int size = end - start;
	char buf[size];
	
	int err = read(fd, buf, size);
	if(err == -1)
		return;
	
	int i;
	for(i = 0; i < size; ++i)
		printf("%c", buf[i]);
	
	printf("\n");
		
	err = close(fd);
	if(err == -1)
		printf("Warning! File %s is not closed.\n", pathname);
}

int main(int argc, char *argv[])
{
	if(argc > 0)
	{
		char *file = argv[1];
		
		//create
		char *hardlink = "hard.c";
		int   err 	   = link(file, hardlink);
		if(err == -1)
			return err;
			
		char *softlink = "soft.c";
		      err 	   = symlink(file, softlink);
		if(err == -1)
			return err;
		
		//print
		PrintFile(hardlink);
		PrintFile(softlink);
		
		//delete
		err = unlink(hardlink);
		if(err == -1)
			printf("Warning! The link %s is not deleted.\n", hardlink);
			
		err = unlink(softlink);
		if(err == -1)
			printf("Warning! The link %s is not deleted.\n", softlink);
	}
	
	return 0;
}
