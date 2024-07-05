#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>

typedef enum e_token_type
{
	COMMAND = 0,
	OPTION = 1,
	STRING = 2,
	VARIABLE = 3,
	EXIT_STATUS = 4,
	RE_IN = 5,
	RE_OUT = 6,
	RE_APPEND = 7,
	HERE_DOC = 8,
	PIPE = 9,
	PATH = 10,
/*	CTRL_C = 11,
	CTRL_D = 12,
	CTRL_BACKSLASH = 13,*/
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	s_token			*next;
} t_token;

# endif
