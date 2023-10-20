#include "monty.h"

/**
 * init_stack - a program that initialises stack.
 * @stack: stacks.
 *
 *
 * Return: 0 if successful or NULL if failure.
 */

void init_stack(Stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}
