#include "factor.h"
/**
 * main - Entry-point for monty interpreter
 *
 * @argc: count of arguments passed to interpreter
 * @argv: location of file to be checked:
 *
 * Return: Always return 0 if succesfull
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char line[100];
    unsigned long int n, p, q;
    int flag;
	
    flag = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(line, sizeof(line), file))
	{
		n = atoi(line);
        for (q = 2; q < n ; q++)
        {
            if (flag == 0)
            {
                if (n % q == 0)
                {
                    p = n / q;
                    printf("%ld = %ld*%ld\n", n, p, q);
                    flag = 1; 
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        memset(line, 0, 100);
	}
	fclose(file);
	return (0);
}
