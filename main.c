#include "monty.h"

stack_t *stack = NULL;
char *command = NULL, *n_value = NULL;
unsigned int line_number = 1;

/**
 * main - function
 * @argc: number of args
 * @argv: array of args
 *
 * Return: void
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[1024], *op;

	void (*f)(stack_t **, unsigned int);

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}


		while (fgets(buffer, sizeof(buffer), file) != NULL)
		{
			op = strtok(buffer, " ");
			command = op;
			op = strtok(NULL, " ");
			n_value = op;

			f = get_op();
			f(&stack, line_number);
			line_number++;
		}
		fclose(file);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
