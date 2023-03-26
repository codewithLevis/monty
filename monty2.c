#include "monty.h"

/**
 *  nop_monty - doesn’t do anything
 * @stack - pointer to data type stack
 * @line_number: current line in opcode
*/
void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar_monty - prints the char at the top of
 * the stack, followed by a new line
 * @stack - pointer to data type stack
 * @line_number: current line in opcode
*/
void pchar_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void)line_number;

	if (temp == NULL)
	{
		track_fail = true;
		err_acc_name("pchar", line_number);
		return;
	}

	if (temp->n < 0 || temp->n > 127)
	{
		track_fail = true;
		err_acc_name("out_of_range", line_number);
		return;
	}

	printf("%c\n", temp->n);
}

/**
 * pstr_monty - prints the string starting at
 * the top of the stack, followed by a new line
 * @stack - pointer to data type stack
 * @line_number: current line in opcode
*/
void pstr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	for (; temp && (temp->n > 0 && temp->n <= 127); temp = temp->next)
	{
		if (temp->n)
		printf("%c", temp->n);
	}
	printf("\n");
	(void)line_number;
}

/**
 * rotl_monty - rotates the stack to the top
 * @stack - pointer to data type stack
 * @line_number: current line in opcode
*/
void rotl_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node, *last_node;


	if ((*stack)->next && (*stack)->next->next)
	{
		first_node = (*stack)->next;
		last_node = (*stack)->next;

		while (last_node->next != NULL)
			last_node = last_node->next;

		first_node->next->prev = *stack;
		(*stack)->next = first_node->next;
		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL;
	}

	(void) line_number;
}

/**
 * rotr_monty - rotates the stack to the bottom
 * @stack - pointer to data type stack
 * @line_number: current line in opcode
*/
void rotr_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	(void)line_number;

	if ((*stack)->next && (*stack)->next->next)
	{
		head = (*stack)->next;
		tail = head;

		while (tail->next != NULL)
			tail = tail->next;

		for (int i = 0; i < 2; i++)
		{
			tail->next = head;
			head->prev = tail;
			tail = head;
			head = head->prev;
			tail->prev = NULL;
			(*stack)->next = tail;
		}
	}
}
