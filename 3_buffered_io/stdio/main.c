#include <stdio.h>

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

/* FILE * fopen(const char * path, const char * mode);
 *
 * DESCRIPTION:
 * 	mode: r | r+ | w | w+ | a | a+ | b (might be ignored by linux)
 *
 * RETURN:
 * 	return a FILE pointer(FILE *) if success
 * 	return NULL and set errno if failed
 * STREAM:
 * 	we call a FILE* object 'stream'
 */


int main(){
	/* variables definition area */
	FILE *stream;

	/* end definition area */
	printf("============ <START> =============\n");
	/* main process */	
	stream = fopen(FILENAME, "r");
	if (!stream)
		printf("[*] Failed!\n");

	printf("[=] Success!\n");


	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
