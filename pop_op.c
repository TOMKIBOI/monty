#include "monty.h"

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number
 * Return: void
 */
void _pop(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}
