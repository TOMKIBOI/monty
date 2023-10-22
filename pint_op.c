#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number
 * Return: void
 */
void _pint(stack_t **doubly, unsigned int line_number)
{
	(void)line_number;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_programContext();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}