#include "monty.h"

/**
 * f_pstr - print string at the top of stack
 * @head: first node of linked list
 * @line_number: line line_number
 *
 * Return: none
 */

void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
