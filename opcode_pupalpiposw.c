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
