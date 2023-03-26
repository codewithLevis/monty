#include "monty.h"

/**
 * parse - splits a string
 * @op_tok: token holder
 * @line: line read
 * Return: void
*/
int parse(char ***op_tok, char *line)
{
	int wc, i, j;
	words parsed_w;

	if (line == NULL)
		return (-1);
	if (only_delim(line, DELIMS))
		return (0);

	wc = word_count(line, DELIMS);
	*op_tok = malloc(sizeof(char *) * (wc + 1));
	parsed_w.pos = 0;
	i = 0;

	while (i < wc)
	{
		get_word(&parsed_w, line, DELIMS);
		(*op_tok)[i] = malloc(sizeof(char) * (parsed_w.word_len + 1));

		if ((*op_tok)[i] == NULL)
		{
			while (i--)
				free((*op_tok)[i]);
			free(*op_tok);
			free(parsed_w.word);
			return (-1);
		}
		j = 0;
		while (j < parsed_w.word_len)
		{
			(*op_tok)[i][j] = parsed_w.word[j];
			j++;
		}
		(*op_tok)[i][j] = '\0';
		free(parsed_w.word);
		i++;
	}
	(*op_tok)[i] = NULL;

	return (1);
}


/**
 * only_delim - if line is made of whitespace characters only
 * @line: opcode line
 * @delim: DELIMS
 * Return: bool
*/
bool only_delim(char *line, char* delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
			break;
		}

		if (delim[j] == '\0')
			return (false);
	}

	return (true);
}

/**
 * is_delim - checks for delimeter
 * @ch: character
 * @delims: delimiters
 * Return: 0 or 1
*/
int is_delim(char ch, char *delims)
{
	int i;

	for (i = 0; delims[i]; i++)
	{
		if (ch == delims[i])
		return (1);
	}

	return (0);
}

/**
 * word_count - checks for delimeter
 * @line: opcode line
 * @delims: delimiters
 * Return: word count
*/
int word_count(char *line, char *delims)
{
	int count = 0;
	bool in_word = false;

	for (int i = 0; line[i] != '\0'; i++)
	{
		if (!in_word && !is_delim(line[i], delims))
		{
			in_word = true;
			count++;
		}
		else if (in_word && is_delim(line[i], delims))
			in_word = false;
	}
	return (count);
}

/**
 * get_word - generates words for the opcode line
 * @ptr: pointer to words struct
 * @line: opcode line
 * @delims: DELIMS
 * Return: void
*/
void get_word(words *ptr, char *line, char *delim)
{
	int i, j, k;
	char ch;

	if (ptr == NULL)
	return;

	for (; line[ptr->pos]; ptr->pos++)
	{
		ch = line[ptr->pos];
		for (j = 0; delim[j]; j++)
		{
			if (ch == delim[j])
			break;
		}
		if (!delim[j])
			break;
	}
	k = ptr->pos;

	for (i = 0; line[ptr->pos]; ptr->pos++, i++)
	{
		if (is_delim(line[ptr->pos], delim))
			break;
	}
	ptr->word_len = i;
	ptr->word = malloc(sizeof(char) * (i + 1));

	if (ptr->word == NULL)
		return;

	for (j = 0; k < ptr->pos; k++, j++)
		ptr->word[j] = line[k];
	ptr->word[j] = '\0';
}
