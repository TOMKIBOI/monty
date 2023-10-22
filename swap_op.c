#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number
 * Return: void
 */
void _swap(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
