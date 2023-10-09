#include "monty.h"

/**
 * op_div - divides the second top element of the stack
 * by the topmost element
 * @stack: pointer to the head of stack
 * @line_number: line number of operation command
 *
 * Return: void
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	int temp_n, len;

	len = length_of_stack(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",\
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = (*stack)->n;
	(*stack)->next->n /= temp_n;
	pop(stack, line_number);
}

/**
 * op_mul - prints the result of the multiplication of the
 * top two nodes of the stack to the stdout
 * @stack: stack
 * @line_number: line number of operation code
 * Return: void
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	int temp_n, len;

	len = length_of_stack(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",\
			line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = (*stack)->n;
	(*stack)->next->n *= temp_n;
	pop(stack, line_number);
}
