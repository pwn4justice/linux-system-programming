#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

/* ssize_t read(int fd, void *buf, size_t len);
 *
 * DESCRIPTION: read 'len' bytes to '*buf' from 'fd', return -1 if failed
 * RETURN VALUE: number of bytes be written if success
 * ERRNO: set
 *
 */

const char *FILENAME = "/home/logan/linux_lab/2/test_data/article.txt";

int main(){
	char buffer[11];
	ssize_t nr;

	int fd = open(FILENAME, O_RDONLY);
	nr = read(fd, buffer, 10);

	buffer[10] = '\0';

	if(nr == -1){
		printf("read error, errno: \n", errno);
		return -1;
	}
	printf("nr = %ld, %s\n", nr, buffer);
	printf("\n");
	printf("buffer[9] is '%c'\n", buffer[9]);
	printf("buffer[8] is '%c'\n", buffer[8]);
	printf("buffer[7] is '%c'\n", buffer[7]);
	
	
	

	return 0;
}
