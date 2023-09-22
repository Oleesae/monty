#include "monty.h"

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

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n_value == NULL)
	{
		free(new_node);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
	if (!head)
		exit(EXIT_FAILURE);
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
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	while (head->prev != NULL)
		head = head->prev;
	printf("%d\n", head->n);
	(void)line_number;
}
