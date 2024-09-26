#include "monty.h"

/**
 * free_stack - freedoubly linked list
 * @head: first node of stack
 * Return: none
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * f_stack - free stack
 * @head: first node(unused)
 * @line_number: line line_number (unused)
 *
 * Return: none
*/

void f_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	bus.lifi = 0;
}
