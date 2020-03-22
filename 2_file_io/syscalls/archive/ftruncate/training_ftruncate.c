#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

//#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define FILENAME "/home/logan/linux_lab/linux-system-programming/2_file_io/test_data/pirate.txt"

/* int ftruncate(int fd, off_t len);
 *
 * DESCRIPTION:
 * 	cut FILE to the length: 'len'
 * 	similar as "int truncate(const char *path, off_t len)"
 *
 * return -1 and set errno if failed
 * return 0 if success
 */

int main(){
	/* variables definition area */
	int ret;
	int fd, i = 0;
	char c;
	
	/* end definition area */
	printf("============ <START> =============\n");
	/* main process */	
	ret = truncate(FILENAME, 45);	// original file has 74 bytes.
	/* cut the file to 45 bytes */

	if (ret == -1){
		perror("truncate");
		return -1;
	}

	/* print the cutted file */
	fd = open(FILENAME, O_RDONLY);
	while(pread(fd, &c, (size_t)1, i)){
		printf("%c", c);
		i++;
	}

	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
