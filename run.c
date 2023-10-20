#include "monty.h"

/**
 * execute - a program that executes a code.
 * @stack: stacks.
 * @opcode: code.
 * @value: integer.
 *
 *
 * Return: 0 if successful or NULLfailure.
 */

void execute(Stack *stack, char *opcode, int value)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, value);
	} else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack);
	} else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack);
	} else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	} else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack);
	} else if (strcmp(opcode, "add") == 0)
	{
		add(stack);
	} else
	{
		fprintf(stderr, "Error: Unknown opcode '%s'.\n", opcode);
		exit(EXIT_FAILURE);
	}
}
