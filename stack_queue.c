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


/**
 * shift_default - confirm for change btw stack and queue
 * @stack: pointer to data type stack_t
 * Return: 0 or 1
*/
int shift_default(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
}

/**
*add_node - adds node at the beginning or end
* @stack: pointer to data type stack_t
*@new: pointer to new member of data type stack_t
*/
void add_node(stack_t **stack, stack_t **new)
{
	stack_t *temp;
	stack_t *new_p = (*new);

	/*Add node at the beginning*/
	if (shift_default(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_p->next = temp;
		new_p->prev = NULL;
		if (temp != NULL)
		temp->prev = new_p;
		(*stack)->next = new_p;
	}
	/**
	* It is 0
	* Add node to the end
	* Queue
	*/
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		temp = temp->next;
		temp->next = new_p;
		new_p->prev = temp;
		new_p->next = NULL;
	}
}
