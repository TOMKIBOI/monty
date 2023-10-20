#include "monty.h"

/**
 * swap - a program that swaps stacks.
 * @stack: stacks.
 *
 * Return: 0 if successful or NULLfailure.
 */

void swap(Stack *stack)
{
	int temp;

	if (stack->size < 2)
	{
		fprintf(stderr, "Error: can't swap with less than two elements.\n");
		exit(EXIT_FAILURE);
	}
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}
