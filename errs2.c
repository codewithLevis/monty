#include "monty.h"

/**
*err_acc_name - prints error by name
*@name: name of function
*@line_no: current line number
*Return: void
*/
void err_acc_name(char *name, unsigned int line_no)
{
	if (strcmp(name, "pint"))
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
	if (strcmp(name, "pchar"))
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
	if (strcmp(name, "zero"))
		fprintf(stderr, "L%u: division by zero\n", line_no);
	if (strcmp(name, "out_of_range"))
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
	else
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_no, name);
}
