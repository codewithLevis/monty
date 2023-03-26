#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUF 1024
#define DELIMS " \t\n\r\a\b"
#define STACK 0
#define QUEUE 1
bool track_fail = false;
char **op_token = NULL;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct words - manipulates words in a line of opcodes
 * @pos: maintains upto the current point read
 * @wordlen: len of current word
 * @word: word read
*/
typedef struct words
{ 
	int pos;
	int word_len;
	char *word;
}words;
/*Monty functions*/
void push_monty(stack_t **stack, unsigned int line_number);
void pall_monty(stack_t **stack, unsigned int line_number);
void pint_monty(stack_t **stack, unsigned int line_number);
void pop_monty(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void add_monty(stack_t **stack, unsigned int line_number);
void nop_monty(stack_t **stack, unsigned int line_number);
void sub_monty(stack_t **stack, unsigned int line_number);
void div_monty(stack_t **stack, unsigned int line_number);
void mul_monty(stack_t **stack, unsigned int line_number);
void mod_monty(stack_t **stack, unsigned int line_number);
void pchar_monty(stack_t **stack, unsigned int line_number);
void pstr_monty(stack_t **stack, unsigned int line_number);
void rotl_monty(stack_t **stack, unsigned int line_number);
void rotr_monty(stack_t **stack, unsigned int line_number);
void stack_monty(stack_t **stack, unsigned int line_number);
void queue_monty(stack_t **stack, unsigned int line_number);

/*Error*/
int err_Usage(void);
int err_Open_File(char *file);
int malloc_err(void);
void pop_err(int line_no);
void no_int_err(int line_no);
void err_acc_name(char *name, unsigned int line_no);

/*Line_Handlers*/
int parse(char ***op_tok, char *line);
bool only_delim(char *line, char *delim);
int word_count(char *line, char *delims);
void get_word(words *ptr, char *line, char *delims);

/*Frees and stack*/
void add_node(stack_t **stack, stack_t **new);
int shift_default(stack_t *stack);
bool init_stack(stack_t **stack);
void free_op_tok(char **op_tok);
void free_stack(stack_t **stack);

/*Execute*/
void (*search_func(char *opcode))(stack_t **, unsigned int);
bool execute(char **op_token, stack_t **stack, unsigned int line_number);

#endif /*_MONTY_H_*/
