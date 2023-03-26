#include "monty.h"

/**
 * init_stack - set the stack_t to STACK
 * as default operation in beginnng of program
 * @stack: pointer to member stack_t
 * Return: bool  
*/
bool init_stack(stack_t **stack)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
		return (false);

	temp->n = STACK;
	temp->prev = NULL;
	temp->next = NULL;

	*stack = temp;

	return (true);
}

/**
 * stack_monty - change the stack back to default
 * if changed to QUEUE or retains
 * @stack: pointer to member stack_t
 * @line_number: current line number
 *Return: void
*/
void stack_monty(stack_t **stack, unsigned int line_number)
{
        (*stack)->n = STACK;

	(void)line_number;
}

/**
 * queue_monty - shift default to QUEUE
 * @stack: pointer to member stack_t
 * @line_number: current line number
 * Return: void
*/
void queue_monty(stack_t **stack, unsigned int line_number)
{
        (*stack)->n = QUEUE;

	(void)line_number;
}
