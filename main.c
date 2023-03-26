#include "monty.h"

/**
 * main - main program
 * @argc: vector count
 * @argv: ectors
 * Return: 0
*/

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char op_line[BUF];
	unsigned int line_no = 0;
	int valid, verify;
	stack_t *stack = NULL;

	if (argc != 2)
		exit(err_Usage());
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(err_Open_File(argv[1]));
	if (!init_stack(&stack))
		exit(malloc_err());

	while (fgets(op_line, BUF, fp) != NULL)
	{
		line_no++;
		valid = parse(&op_token, op_line);
		if (valid == 0)
			continue;
		else if (valid == -1)
			exit(malloc_err());
		if (op_token[0][0] == '#')
		{
			free_op_tok(op_token);
			continue;
		}
		verify = execute(op_token, &stack, line_no);
		if (verify == 1)
			exit(EXIT_FAILURE);
		else if (verify == -1)
		{
			free_op_tok(op_token);
			break;
		}
		free_op_tok(op_token);
	}
	free_stack(&stack);
	fclose(fp);
	return (0);
}
