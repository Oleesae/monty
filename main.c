#include "monty.h"

stack_t *stack = NULL;
char *n_value = NULL;
unsigned int line_number = 1;
char *command = NULL;
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
	stack_t *temp;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (fgets(buffer, 1024, file) != NULL)
		{
			op = strtok(buffer, " \t\n");
			command = op;
			op = strtok(NULL, " \n\t");
			n_value = op;
			get_op();
			line_number++;
		}
		fclose(file);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	temp = stack;
	while (stack)
	{
		temp = stack;
		stack = temp->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
