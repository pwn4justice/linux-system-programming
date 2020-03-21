#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>  /* printf() */
#include <fcntl.h>  /* open() */


/* off_t lseek(int fd, off_t pos, int origin)
 *
 * DESCRIPTION: 
 * 	origin: SEEK_CUR | SEEK_END | SEEK_SET
 * 	return -1 and set 'errno' if failed
 * 	return (origin +/- pos) if success
 *
 * 	off_t may be is the alian of 'int' type
 *
 * ERROR VALUES:(errno)
 * 	EBADF
 * 	EINVAL
 * 	EOVERFLOW
 * 	ESPIPE
 */

#define FILENAME "/home/logan/linux_lab/2/test_data/article.txt"

int main(){
	/* variables definition area */
	int fd = open(FILENAME, O_RDONLY);
	off_t curr;
	int i = 0;
	char buf;

	/* end definition area */
	printf("\n============ <START> =============\n");
	printf("[=] sizeof 'off_t' is : %d\n", sizeof(off_t));
	printf("[=] sizeof 'long' is : %d\n", sizeof(long));
	printf("[=] sizeof 'long long' is : %d\n", sizeof(long long));
	printf("[=] sizeof 'double' is : %d\n", sizeof(double));
	printf("[=] sizeof 'unsigned int' is : %d\n", sizeof(unsigned int));
	printf("[=] sizeof 'int' is : %d\n", sizeof(int));
	/* main process */	

	curr = lseek(fd, 0, SEEK_CUR);

	if (curr == (off_t)-1)
		/* error */
		printf("[*] Error : lseek()\n");

	printf("[=] Now position is : %d\n", curr);

	/* loop */
	while(i < 100){
		curr = lseek(fd, i, SEEK_SET);
		if (curr == (off_t)-1){
			printf("[*] Error : main.while.lseek()\n");
			return -1;
		}

		printf("[=] Now position is : %d", curr);
		if( read(fd, &buf, sizeof(buf)) == -1)
		       printf("[*] Error : main.while.read()\n");	
		printf(" \tvalue is : %c\n", buf);
		i++;
	}


	/* end main process */
	printf("============= <END> ==============\n\n");
	return 0;
}
