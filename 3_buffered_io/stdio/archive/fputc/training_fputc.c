#include <stdio.h>

/* int fputc(int c, FILE *stream)
 *
 * DESCRIPTION:
 * 	1. let c = (unsigned int)c
 * 	2. put c into stream
 *
 * RETURN:
 * 	success: c
 * 	failed: EOF, set errno
 */

void error(){
	printf("error!\n");
}

void success(){
	printf("success!\n");
}

int main(){
	FILE *stream = stdout;

	if (fputc('p', stream) == EOF)
		error();

	success();
	return 0;
}




