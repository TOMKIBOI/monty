#include "monty,h"

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @line_number: line numbers
 * Return: void
 */
void _pall(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
