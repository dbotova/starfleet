#include "header.h"

int main(void)
{
	char *book;
	char **popular;

	//getting the file
	book = readFile();

	popular = mostUsedWords(book);
	printf("\nMost used words with len >= 4: \n");
	for (int i = 0; i < 255; i++)
	{
		if (popular[i] == NULL)
			break ;
		printf("%s\n", popular[i]);
	}

	return (0);
}



// Function used for the test
// Don't go further :)

#define FILENAME "book.txt"

void	leave(void){
	dprintf(STDERR_FILENO, "Failed to load the file.\n");
	exit(0);
}

char	*readFile(void)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

	printf("Loading the file... ");
	if (NULL == (fp = fopen(FILENAME, "r")))
		leave();
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		leave();
	fread(fcontent, 1, size, fp);
	fclose(fp);
	printf("finish!\n");
	return (fcontent);
}
