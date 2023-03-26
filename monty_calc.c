#include "monty.h"

/**
* add_monty - adds the top two elements of the stack
* @stack: pointer to type stack_t
* @line_number: current line in opcode
*/
void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	if (ptr == NULL || ptr->next == NULL)
	{
		track_fail = true;
		err_acc_name("add", line_number);
		return;
	}

	ptr->next->n += ptr->n;
	pop_monty(stack, line_number);
}

/**
 *sub_monty - subtracts the top element of the stack
 *from the second top element of the stack
 *@stack: pointer to type stack_t
 *@line_number: current line in opcode
*/
void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		track_fail = true;
		err_acc_name("sub", line_number);
		return;
	}

	temp->next->n -= temp->n;
	pop_monty(stack, line_number);
}

/**
 *div_monty - divides the second top element of
 *the stack by the top element of the stack
 *@stack: pointer to type stack_t
 *@line_number: current line in opcode
*/
void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	if (ptr == NULL || ptr->next == NULL)
	{
		track_fail = true;
		err_acc_name("div", line_number);
		return;
	}
	if (ptr->n == 0)
	{
		track_fail = true;
		err_acc_name("zero", line_number);
		return;
	}

	ptr->next->n /= ptr->n;
	pop_monty(stack, line_number);
}

/**
 *mul_monty - multiplies the second top element of
 *the stack with the top element of the stack
 *@stack: pointer to type stack_t
 *@line_number: current line in opcode
*/
void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		track_fail = true;
		err_acc_name("mul", line_number);
		return;
	}

	temp->next->n *= temp->n;
	pop_monty(stack, line_number);
}

/**
 *mod_monty - computes the rest of the
 *division of the second top element of
 *the stack by the top element of the stack
 *@stack: pointer to type stack_t
 *@line_number: current line in opcode
*/
void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		track_fail = true;
		err_acc_name("mod", line_number);
		return;
	}
	if (temp->n == 0)
	{
		track_fail = true;
		err_acc_name("zero", line_number);
		return;
	}

	temp->next->n %= temp->n;
	pop_monty(stack, line_number);
}
