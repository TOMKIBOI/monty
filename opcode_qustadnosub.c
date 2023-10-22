#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _queue(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;

	programContext.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _stack(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;

	programContext.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _add(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, line_number);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _nop(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @line_number: line number;
 * Return: void
 */
void _sub(stack_t **doubly, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_programContext();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, line_number);
}
