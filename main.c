#include "monty.h"

stack_t *stack = NULL;
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int num_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		num_line++;
		process_line(line, num_line);
	}

	fclose(file);
	free(line);
	frstack(stack);

	return (EXIT_SUCCESS);
}

/**
 * process_line - Process a line from the Monty bytecode file
 * @line: Line from the file
 * @line_number: Line number in the Monty bytecode file
 */
void process_line(char *line, unsigned int line_number)
{
	char *opcode;
	instruction_t instruction;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || *opcode == '#')
		return;

	instruction = check(opcode);
	if (instruction.f == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	instruction.f(&stack, line_number);
}

/**
 * check - Get the instruction for a given opcode
 * @opcode: Opcode to search for
 * Return: Structure
 */
instruction_t check(char *opcode)
{
	int i = 0;

	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
                {"add", add},
                {"sub", sub},
                {"div", mdiv},
                {"mul", mul},
                {"mod", mod},
                {"nop", nop},
		{NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(func[i].opcode, opcode) == 0)
			return (func[i]);
		i++;
	}

	return (func[i]);
}

/**
 * frstack - Free the stack
 * @stack: Pointer to the stack
 */
void frstack(stack_t *stack)
{
	stack_t *current = stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
