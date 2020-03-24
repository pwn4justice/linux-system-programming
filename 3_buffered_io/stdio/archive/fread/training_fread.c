#include <stdio.h>

#define FILENAME "./main.elf"

//printf("[*] Error : xxx\n"); // failed printf()
//printf("[=] Error : xxx\n"); // success printf()

/* size_t fread(void *buf, size_t size, size_t nr, FILE *stream)
 *
 * DESCRIPTION:
 * 	read (nr * size) bytes from stream to *buf
 *
 * RETURN:
 * 	success: nr
 * 	failed or EOF : < nr 
 */

FILE *get_stream(const char *filename){
	FILE *stream = fopen(filename, "r");
	if (!stream)
		printf("[*] Error: In get_stream()\n");
	return stream;
}


int main(){
	/* variables definition area */
	FILE *stream;
	char buf[64];
	size_t nr;


	/* end definition area */
	printf("============ <START> =============\n");
	/* main process */	
	stream = get_stream(FILENAME);

	nr = fread(buf, sizeof(buf), 1, stream);
	if (nr == 0)
		/* error */
		printf("[*] Error: In main.if\n");

	printf("nr is : %d\n", nr);


	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
