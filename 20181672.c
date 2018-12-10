#define _CRT_SECURE_NO_WARNINGS
#define MAX_BUFF 500
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE * source;
	FILE * rev;
	char linebuffer[MAX_BUFF], *tokens, *filename;
	int lncnt = 0, wordcnt = 0, charcnt = 0, index;

	if (argc != 2) return -1;

	source = fopen(argv[1], "r");

	filename = strtok(argv[1], ".");
	rev = fopen(strcat(filename, ".rev"), "w");
	if (source)
	{
		while (fgets(linebuffer, MAX_BUFF, source))
		{
			lncnt++;
			index = 0;
			while (linebuffer[index])
			{
				if (linebuffer[index] >= 'A' && linebuffer[index] <= 'Z') linebuffer[index] += 'a' - 'A';
				else if (linebuffer[index] >= 'a' && linebuffer[index] <= 'z') linebuffer[index] -= 'a' - 'A';
				index++;
			}
			fputs(linebuffer, rev);

			tokens = strtok(linebuffer, " \n");
			
			while (tokens)
			{
				wordcnt++;
				charcnt += strlen(tokens);
				
				tokens = strtok(NULL, " \n");
			}
		}
		fflush(rev);
		fclose(source); fclose(rev);

		printf("<Count Result>\n");
		printf("Line count:\t\t%d\n", lncnt);
		printf("Word count:\t\t%d\n", wordcnt);
		printf("Character count:\t%d\n", charcnt);
		printf("File saved to %s", filename);
	}

	return 0;
}
