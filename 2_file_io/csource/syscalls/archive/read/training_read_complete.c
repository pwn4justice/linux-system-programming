#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
//#define SSIZE_MAX LONG_MAX
#include <limits.h> /* which has SSIZE_MAX macro! */


/* ssize_t read(int fd, void *buf, size_t len);
 *
 * DESCRIPTION: read 'len' bytes to '*buf' from 'fd', return -1 if failed
 * RETURN VALUE: number of bytes be written if success
 * ERRNO: set
 *
 */

const char *FILENAME = "/home/logan/linux_lab/2/test_data/article.txt";

int main(){
	char buffer[1024], *buf = buffer;
	long int len = 512;

	int fd = open(FILENAME, O_RDONLY);
	ssize_t ret;
	/* 
	 * ssize_t <= SSIZE_MAX == LONG_MAX, LONG_MAX usually equals to 0x7fffffff in a 32bits computer.
	 * size_t <= SIZE_MAX, which is 'unsigned int' and ssize_t is 'int' in 32bits computer.
	 */

	/* simple safty check */
	if (len > SSIZE_MAX){
		len = SSIZE_MAX;
	}

	while(len != 0 && (ret=read(fd, buf, len)) != 0){
		if (ret == -1){
			if (errno == EINTR)
				continue;
			perror("read");
			break;
		}

		len -= ret;
		buf += ret;
	}

	printf("success...\n");

	return 0;
}
