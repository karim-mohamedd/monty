#include "monty.h"

/**
 * push - pushes an element to my stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	stack_t *new_node;

	argument = strtok(NULL, " \t\n");

	if (!argument || !is_number(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;

        (void)line_number;
        while (current)
        {
                printf("%d\n", current->n);
                current = current->next;
        }
}

/**
 * is_number - checks if a string represents a valid integer
 * @str: string to check
 * Return: 1 if it's a number, 0 otherwise
 */

int is_number(char *str)
{
	char c;
	int i = 0;

	if (str == NULL || *str == '\0')
		return 0;

	while ((c = str[i]) != '\0')
	{
		if (i == 0 && (c == '-' || c == '+'))
		{
		i++;
		continue;
		}

		if (!(c >= '0' && c <= '9'))
		return 0;

		i++;
	}

	return 1;
}
