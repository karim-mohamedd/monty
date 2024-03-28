#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *top;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }


        top = (*stack)->next;
        (*stack)->next = top->next;
        top->prev = (*stack)->prev;
        (*stack)->prev = top;
        top->next = *stack;
        *stack = top;
}