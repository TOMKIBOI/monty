#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number
 * Return: void
 */
void _push(stack_t **doubly, unsigned int line_number)
{
	int n, j;

	if (!programContext.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_programContext();
		exit(EXIT_FAILURE);
	}

	for (j = 0; programContext.arg[j] != '\0'; j++)
	{
		if (!isdigit(programContext.arg[j]) && programContext.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_programContext();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(programContext.arg);

	if (programContext.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

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
