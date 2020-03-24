#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

//#define LINE_MAX 100
#include <limits.h>	/* #define LINE_MAX xxx */

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

//printf("[*] Error : xxx\n"); // failed printf()
//printf("[=] Error : xxx\n"); // success printf()


/* char * fgets(char *str, int size, FILE *stream)
 *
 * DESCRIPTION:
 * 	This function reads (size-1) bytes from stream and save contents(includes '\n') 
 * 	to *str, it also will end when met 'EOF' or '\n', '\0' will be appended automatically.
 *
 * RETURN:
 * 	success: return char*
 * 	failed: return NULL
 */

int main(){
	/* variables definition area */
	char buf[LINE_MAX];
	FILE *stream = fopen(FILENAME, "r");

	/* end definition area */
	if (!stream)
		printf("[*] Error : main.if(!stream)\n"); // failed printf()

	printf("============ <START> =============\n");
	/* main process */	
	if (!fgets(buf, LINE_MAX, stream))
		printf("[*] Error : main.if(!fgets)\n"); // failed printf()

	printf("[=] Success : \nLINE_MAX is %d\nbuf is : '%s'\n", LINE_MAX, buf); // success printf()



	/* end main process */
	printf("============= <END> ==============\n");
	return 0;
}
