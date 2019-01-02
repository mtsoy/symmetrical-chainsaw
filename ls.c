#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	DIR *dirp = opendir(argv[1]);

	struct dirent *d_buf;
	struct stat *f_buf;
	while(1)
	{
		d_buf = readdir(dirp);
		if(d_buf == NULL)
			break;
		
		stat(d_buf -> d_name, f_buf);
		printf("%d %d %d %d %d ", f_buf -> st_mode,    /* protection */
								 f_buf -> st_nlink,   /* number of hard links */
							     f_buf -> st_size,    /* total size, in bytes */
							     f_buf -> st_atime,   /* time of last access */
							     f_buf -> st_mtime   /* time of last modification */);

		printf("%s\n", d_buf -> d_name);
	}
	
	closedir(dirp);
	
	return 0;
}
