#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>  /* printf() */
#include <fcntl.h>  /* open() */


#define FILENAME "/home/logan/linux_lab/linux-system-programming/2_file_io/test_data/article.txt"

/* ssize_t pread(int fd, void *buf, size_t count, off_t pos);
 *
 * DESCRIPTION:
 * 	This syscall reads 'count' bytes from 'pos' position of file 'fd' to 'buf' area.
 * 	basically pwrite is the same:
 * 		ssize_t pwrite(int fd, const void *buf, size_t count, off_t pos);
 * 	Those two syscalls don't care where the in-position is of the file! They just do their own.
 *
 */

int main(){
	/* variables definition area */

	int fd = open(FILENAME, O_RDONLY);
	char buf;
	off_t i = 0;

	/* end definition area */

	printf("\n============ <START> =============\n");

	/* main process */	
	while(i < 100){
		if(pread(fd, &buf, sizeof(char), i))
			printf("[=] Position is : %d, \t value is : %c\n", i, buf);
		i++;
	}
	
	/* end main process */

	printf("============= <END> ==============\n\n");
	return 0;
}
