#include "monty.h"

/**
 * length_of_stack - returns the length of the stack
 * @stack: pointer to head of stack
 *
 * Return: int
 */

int length_of_stack(stack_t **stack)
{
	stack_t *head;
	int len;

	head = *stack;
	if (!head)
		return (0);
	while (head->prev != NULL)
		head = head->prev;
	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}

	return (len);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: line of operation command
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int len;
	size_t temp_n;

	len = length_of_stack(&head);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n"\
			, line_number);
		exit(EXIT_FAILURE);
	}

	temp_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_n;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: line number to operation command
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len;
	int tmp_n;

	head = *stack;
	len = length_of_stack(&head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",\
			line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	tmp_n = head->n;
	(*stack)->n += tmp_n;
	free(head);
}
