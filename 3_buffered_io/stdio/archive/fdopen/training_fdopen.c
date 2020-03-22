#include <stdio.h>
#include <fcntl.h>	/* open() and O_RDONLY */

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

/* FILE * fdopen(int fd, const char * mode);
 *
 * DESCRIPTION:
 * 	mode: r | r+ | w | w+ | a | a+ | b (might be ignored by linux)
 *	transfer the fd object to a stream object.
 * RETURN:
 * 	return a FILE pointer(FILE *) [aka. stream] if success
 * 	return NULL and set errno if failed
 * STREAM:
 * 	we call a FILE* object 'stream'
 * ATTENTION:
 * 	while a stream is correlated with a file descriptor, you should
 * 	NOT manipulate the fd any more. Although it's legal. 	
 */


int main(){
	/* variables definition area */
	int fd;
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

	printf("[=] Success!\n");


	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
