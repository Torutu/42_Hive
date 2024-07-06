
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include "./inc/libft/libft.h"

typedef enum e_token_type
{
	COMMAND,
	OPTION,
	STRING,
	VARIABLE,
	EXIT_STATUS,
	RE_IN,
	RE_OUT,
	RE_APPEND,
	HERE_DOC,
	PIPE,
	PATH,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	char			*flag;
	struct s_token	*next;
}				t_token;

#endif
