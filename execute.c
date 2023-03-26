#include "monty.h"
/**
 * execute - call functions and executes it
 * @op: op_tokens
 * @line_no: line number
 * @stack: pointer to the stack
 *@fp: file stream
 *Return: 0, 1 or -1
*/
int execute(char **op, stack_t **stack, unsigned int line_no, FILE *fp)
{
	void (*_monty_ptr)(stack_t **, unsigned int);

	_monty_ptr = search_func(op[0]);

	if (_monty_ptr == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_no, op[0]);
		free_op_tok(op);
		free_stack(stack);
		fclose(fp);
		return (1);
	}

	_monty_ptr(stack, line_no);

	if (track_fail)
		return (-1);
	return (0);
}

/**
 * search_func - search for required function
 * @opcode: opcode command
 * Return: void
*/
void (*search_func(char *opcode))(stack_t **, unsigned int)
{
	int i;
	instruction_t funcs[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", stack_monty},
		{"queue", queue_monty},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(funcs[i].opcode, opcode) == 0)
			return (funcs[i].f);
	}
	return (NULL);
}
