#include "monty.h"

/**
 * push_monty - pushes an element to the stack
 * element added depending on the stack next
 * @stack: pointer to stack
 * @line_number: line at the opcode file
 * Return: void
*/
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i;

	(void)line_number;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		track_fail = true;
		malloc_err();
		return;
	}
	if (op_token[1] == NULL)
	{
		free(new);
		track_fail = true;
		no_int_err(line_number);
		return;
	}

	for (i = 0; op_token[1][i]; i++)
	{
		if (op_token[1][i] == '-' && i == 0)
			continue;
		if (op_token[1][i] < '0' || op_token[1][i] > '9')
		{
			free(new);
			track_fail = true;
			no_int_err(line_number);
			free_op_tok(op_token);
			return;
		}
	}
	new->n = atoi(op_token[1]);
	new->next = NULL;
	new->prev = NULL;

	add_node(stack, &new);
}

/**
 * pall_monty - prints all the values on the stack
 *  starting from the top of the stack
 * @stack: pointer to stack
 * @line_number: line at the opcode file
 * Return: void
*/
void pall_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void) line_number;
}

/**
 * pint_monty - prints the value at the top of the stack
 *  followed by a new line.
 * @stack: pointer to stack
 * @line_number: line at the opcode file
 * Return: void
*/
void pint_monty(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack)->next == NULL)
	{
		track_fail = true;
		err_acc_name("pint", line_number);
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pop_monty - removes the top element of the stack
 * @stack: stack pointer
 * @line_number: line at the opcode file
 * Return: void
*/
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void)line_number;

	if (temp == NULL)
	{
		track_fail = true;
		pop_err(line_number);
		return;
	}

	if (temp->next != NULL)
	temp->next->prev = *stack;
	(*stack)->next = temp->next;
	free(temp);
}

/**
 * swap_monty - swaps the top two elements of the stack
 * @stack: stack pointer
 * @line_number: line at the opcode file
 * Return: void
*/
void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = (*stack)->next;

	(void)line_number;

	if (temp2 == NULL || temp2->next == NULL)
	{
		track_fail = true;
		err_acc_name("swap", line_number);
		return;
	}

	temp = temp2->next;
	temp2->next = temp->next;
	temp2->prev = temp;
	if (temp->next)
		temp->next->prev = temp2;
	temp->next = temp2;
	temp->prev = *stack;
	(*stack)->next = temp;
}
