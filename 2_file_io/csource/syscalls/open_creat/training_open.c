#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>


/* int open(const char *name, int flags [, mode_t mode]);
 * 	name:  filename
 * 	flags: O_RDONLY | O_WRONLY | O_RDWR
 * 	[ 
 * 	flags more:
 * 		O_APPEND
 * 		O_ASYNC, socket or tty only
 * 		O_CREAT, 'mode' parameter must be given!
 * 		O_DIRECT
 * 		O_DIRECTORY
 * 		O_EXCL
 * 		O_LARGEFILE
 * 		O_NOCTTY
 * 		O_NOFOLLOW
 * 		O_NONBLOCK, FIFO files only
 * 		O_SYNC
 * 		O_TRUNC, ignore when the file is FIFO or /dev/ttyxx
 * 	]
 * 	mode: ex. 0644 or below:
 * 		S_IRWXU , S_IRUSR , S_IWUSR , S_IXUSR
 * 		S_IRWXG , S_IRGRP , S_IWGRP , S_IXGRP 
 * 		S_IRWXO , S_IROTH , S_IWOTH , S_IXOTH
 *
 * return value: fd(file descriptor)
 *
 * BTW: you should notice that there is a thing called "umask", usually values '022'
 */ 

/* int creat(const char * name, mode_t mode);
 *
 * it equals to : open( name, O_WRONLY | O_O_CREAT | O_TRUNC , mode)
 */

int main(){
	int fd;

	fd = open("/home/logan/linux_lab/2/test_data/article.txt", O_RDONLY);

	if (fd == -1)	/* means error */
	{
		//do error things..
		//
		printf("Open file error!\n");
		return -1;
	}

	printf("Congradulations! Success...\n");


	return 0;
}
