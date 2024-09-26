#include "monty.h"

/**
* f_pall - print everything in stack
* @head: pointer to pointer of first node
* @line_number: line line_number (not used)
*
* Return: none
*/

void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* f_swap - swap first two elements of stack
* @head: first node
* @line_number: line line_number
*
* Return: none
*/

void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.bytecode_file);
		free(bus.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
