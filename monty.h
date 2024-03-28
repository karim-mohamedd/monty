#ifndef MONTY_H
#define MONTY_H
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */

/* push.c */
void push(stack_t **stack, unsigned int line_number);

/* pall.c */
void pall(stack_t **stack, unsigned int line_number);

/* pop.c */
void pop(stack_t **stack, unsigned int line_number);

/* pint.c */
void pint(stack_t **stack, unsigned int line_number);

/* swap.c */
void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mdiv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* nop.c */
void nop(stack_t **stack, unsigned int line_number);


/* helpers.c */
void frstack(stack_t *stack);
void process_line(char *line, unsigned int line_number);
instruction_t check(char *opcode);
int is_number(char *str);

#endif
