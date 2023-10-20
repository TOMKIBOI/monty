#include "monty.h"

/**
 * main - entry point to the program.
 * @argc: argument count.
 * @argv: args vector.
 *
 * Return: 0 on successful execution, or NULL if failure.
 */

int main(int argc, char *argv[])
{
	char opcode[10];
	int value;
	FILE *file = fopen(argv[1], "r");
	Stack stack;

	if (argc != 2)
	{	fprintf(stderr, "Usage: %s <monty_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (file == NULL)
	{	fprintf(stderr, "Error: Unable to open file %s.\n", argv[1]);
		return (EXIT_FAILURE);
	}
	init_stack(&stack);
	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) == 1)
			{
				execute(&stack, opcode, value);
			} else
			{	fprintf(stderr, "Error: Invalid 'push' instruction.\n");
				exit(EXIT_FAILURE);
			}
		} else
		{
			execute(&stack, opcode, 0);
		}
	}
	fclose(file);
	while (stack.top != NULL)
	{
		Node *temp = stack.top;

		stack.top = stack.top->next;
		free(temp);
	}
	return (0);
}
