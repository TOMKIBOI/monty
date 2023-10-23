#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _div(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, line_number);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _mul(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, line_number);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _mod(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, line_number);
}
/**
 * _pchar - print the char value of the first element
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _pchar(stack_t **doubly, unsigned int line_number)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _pstr(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}