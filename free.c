#include "monty.h"

/**
 * free_op_tok - frees words token
 * @op_tok: words token
 * Return: void
*/
void free_op_tok(char **op_tok)
{
	int i;

	if (op_tok != NULL)
	{
		for (i = 0; op_tok[i]; i++)
			free(op_tok[i]);
		free(op_tok);
	}
}

/**
 * free_stack - frees stack
 * @stack: pointer to data type stack_t
 * Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (*stack != NULL)
	{
		while (*stack)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = temp;
		}
	}
}
