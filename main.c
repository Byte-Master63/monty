#include "monty.h"
#define _GNU_SOURCE

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *bytecode_file;
	size_t buffer_size = 0;
	ssize_t line_length = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecode_file = fopen(argv[1], "r");
	bus.file = bytecode_file;

	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_length > 0)
	{
		line_content = NULL;
		line_length = getline(&line_content, &buffer_size, bytecode_file);
		bus.content = line_content;
		line_number++;

		if (line_length > 0)
			execute(line_content, &stack, line_number, bytecode_file);

		free(line_content);
	}

	free_stack(stack);
	fclose(bytecode_file);
	return (0);
}
