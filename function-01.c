#include "monty.h"

/**
 * f_pop - print top node on stack
 * @head: pointer to pointer of first node
 * @line_number: line line_number
 *
 * Return: none
 */

void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.bytecode_file);
		free(bus.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

/**
 * f_pint - print top node on stack
 * @head: pointer to pointer of first node
 * @line_number: line line_number
 *
 * Return: none
 */

void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.bytecode_file);
		free(bus.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * f_nop - do nothing
 * @head: pointer to pointer of first node
 * @line_number: line line_number
 *
 * Return: none
 */

void f_nop(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;
}
