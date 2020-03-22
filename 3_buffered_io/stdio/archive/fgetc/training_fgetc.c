#include <stdio.h>

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

/* int fgetc(FILE * stream)
 *
 * DESCRIPTION:
 * 	read a single bytes from the stream.
 *
 * 	return 'int' is very important!
 * 	if you use a 'char' variable to receive return value, things migth go
 * 	wrong...
 *
 * RETURN:
 * 	fail: EOF
 * 	success: (int)(the bytes from the stream)
 */

int main(){
	/* variables definition area */
	FILE *stream;
	int ch;

	/* end definition area */
	printf("============ <START> =============\n");
	/* main process */	
	stream = fopen(FILENAME, "r");
	if (!stream)
		printf("[*] Failed! In: main.if(!stream)\n");
	
	ch = fgetc(stream);
	if (ch == EOF)
		printf("[*] Failed! In: main.if(ch == EOF)\n");
	
	if (fclose(stream))
		printf("[*] Failed! In: main.if(fclose())\n");

	printf("[=] Success! The bytes I read is : %c\n", (char)ch);


	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
