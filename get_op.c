#include "monty.h"

/**
 * get_op - returns a pointer to a function that matches
 * the string s
 * @s: string
 *
 * Return: void
 */

void (*get_op())(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	if (command == NULL)
		return (NULL);


	while (opcodes[i].opcode)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
