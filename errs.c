#include "monty.h"

/**
 * err_Usage - prints usage error
 * Return: failure
*/
int err_Usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * err_Open_File - prints file open error
 *@file: second argument
 * Return: failure
*/
int err_Open_File(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}

/**
 * malloc_err - allocation error
 * Return: failure
*/
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * pop_err - pop error
 *@line_no: position at opcode
 * Return: void
*/
void pop_err(int line_no)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
}

/**
 * no_int_err - no integer error
 *@line_no: position at opcode
 * Return: void
*/
void no_int_err(int line_no)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
}
