#include "monty.h"

/**
 * pop - Removes the first element of the stack
 * @stack: Stack pointer
 * @line_number: Number of the line in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *command;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	command = *stack;
	*stack = command->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(command);
}


