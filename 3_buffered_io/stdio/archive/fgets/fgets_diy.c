#include <stdio.h>
#include <limits.h>

#define FILENAME "/home/logan/linux_lab/linux-system-programming/test_data/article.txt"

char *ffgets(char *buffer, int size, FILE *stream){
	char *s = buffer;
	int c = 0;

	while(--size > 0 && (c = fgetc(stream)) != EOF)
		*s++ = c;	// ++ > *
		*s = '\0';
}

char *ffgets_with_specific_delimiter(char *buffer, int size, FILE *stream, char delimiter){
	char *s = buffer;
	int c = 0;

	/* if delimiter == '\n', then this function is similar to fgets(), but slower! */
	while(--size > 0 && (c = fgetc(stream)) != EOF && printf("=>%c\n", c) && (*s++ = c) != delimiter);
	if (c == delimiter){
		printf("=========\n");
		*--s = '\0';
	}
	else
		*s = '\0';
}


int main(){
	char buf[LINE_MAX];
	char *temp;

	FILE *stream = fopen(FILENAME, "r");
	if (!stream)
		printf("xxxxxxxxxxxx\n");

	temp = ffgets_with_specific_delimiter(buf, LINE_MAX, stream, '\"');

	printf("[=] The string is: %s\n", buf);


	return 0;
}
