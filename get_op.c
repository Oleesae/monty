#include "monty.h"

/**
 * get_op - returns a pointer to a function that matches
 * the string s
 * @s: string
 *
 * Return: void
 */

void (*get_op(char *s))(stack_t **, unsigned int)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
		i++;
	}
	printf("L<%d>: unknown instruction <%s>\n", line_number, command);
	exit(EXIT_FAILURE);
}
