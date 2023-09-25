#include "monty.h"

/**
 * isvalid_int - checks if a given string is a valid integer
 * @str: string
 *
 * Return: 1 if str is a valid integer. 0 otherwise
 */
int isvalid_int(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '-' || i != 0)
				return (0);
		}
	}

	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: head of stack
 * @line_number: line number of op_codes
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *head;

	if (!n_value || !isvalid_int(n_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(n_value);
	head = *stack;
	if (!head)
		*stack = new_node;
	else
	{
		new_node->next = head;
		head->prev = new_node;
		*stack = new_node;
	}
	(void)line_number;
}

/**
 * pall - prints all the elements of the stack
 * @stack: head of the stack
 * @line_number: line number of the op code
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (*stack == NULL)
		return;
	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	(void)line_number;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the stack
 * @line_number: line number of op code
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (head->prev != NULL)
		head = head->prev;
	printf("%d\n", head->n);
	(void)line_number;
}

/**
 * pop - removes the top element of the stack
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
