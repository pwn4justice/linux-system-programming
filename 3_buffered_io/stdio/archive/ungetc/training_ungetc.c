#include <stdio.h>

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

/* int ungetc(int c, FILE * stream)
 *
 * DESCRITPTION:
 * 	convert c to unsigned int, and put back to the stream!
 * 	that means: you could 'spy' on stream, take a watch then put it back.
 * RETURN:
 * 	return c if success, and if you access stream again, you'll get c.
 * 	return EOF if failed	
 */

// Question: How to design an elegant sleep() function?
void sleep(int ms);

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
	printf("[=] Get a bytes from steam");	

	/* fgetc */
	ch = fgetc(stream);
	if (ch == EOF)
		printf("[*] Failed! In: main.if(ch == EOF)\n");

	printf("\n[=] Done, ch is : [%c]\n", ch);	
	
	/* ungetc */
	printf("[=] Put the bytes back to the steam");	

	ch = ungetc(ch, stream);
	if (ch == EOF)
		printf("[*] Failed! In: main.if(ch == EOF).2\n");
	printf("\n[=] Done...\n");	

	/* fgetc again */
	printf("[=] Get a bytes from steam AGAIN");	
	ch = fgetc(stream);

	if (ch == EOF)
		printf("[*] Failed! In: main.if(ch == EOF).3\n");
	printf("\n[=] Done, ch is : [%c]\n", ch);	

	if (fclose(stream))
		printf("[*] Failed! In: main.if(fclose())\n");

	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
