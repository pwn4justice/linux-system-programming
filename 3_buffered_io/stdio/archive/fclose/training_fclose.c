#include <stdio.h>
#include <fcntl.h>	/* open() and O_RDONLY */

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

/* int fclose(FILE * stream)
 *
 * DESCRIPTION:
 * 	flush buffer, and close the stream.
 * RETURN:
 * 	success: 0
 * 	fail: EOF and set errno
 */

int main(){
	/* variables definition area */
	int fd, ret;
	FILE *stream;

	/* end definition area */
	printf("============ <START> =============\n");
	/* main process */	
	fd = open(FILENAME, O_RDONLY);
	if (fd == -1)
		printf("[*] Failed! In: main.if(!fd) \n");

	stream = fdopen(fd, "r");
	if (!stream)
		printf("[*] Failed! In: main.if(!stream) \n");

	ret = fclose(stream);
	if (ret != 0)
		printf("[*] Failed! In: main.if(ret) \n");


	printf("[=] Success!\n");


	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
