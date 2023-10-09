#include "monty.h"

/**
 * get_op - returns a pointer to a function that matches
 * the string s
 *
 * Return: void
 */

void (*get_op())(stack_t **, unsigned int)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", op_div},
		{"mul", op_mul},
		{NULL, NULL}
	};

	if (command == NULL)
		return (NULL);
	i = 0;
	while (opcodes[i].opcode != NULL && command)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&stack, line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
