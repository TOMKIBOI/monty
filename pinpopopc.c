#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stacks.
 *
 * Return: top data.
 */

void pint(Stack *stack)
{
	if (stack->size == 0)
	{
		fprintf(stderr, "Error: can't pint an empty stack.\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->top->data);
}

#include "monty.h"

/**
 * pop - a function that transfer the node.
 * @stack: stacks
 *
 * Return: returns the data or Exit if failure.
 */

void pop(Stack *stack)
{
	Node *temp = stack->top;

	if (stack->size == 0)
	{
		fprintf(stderr, "Error: can't pop an empty stack.\n");
		exit(EXIT_FAILURE);
	}
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
}
