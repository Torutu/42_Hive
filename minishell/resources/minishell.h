
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft.h"

typedef enum e_token_type
{
	COMMAND = 1,
	OPTION = 2,
	STRING = 3,
	VARIABLE = 4,
	EXIT_STATUS = 5,
	RE_IN = 6,
	RE_OUT = 7,
	RE_APPEND = 8,
	HERE_DOC = 9,
	PIPE = 10,
	PATH = 11,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	char			*flag;
	struct s_token	*next;
}				t_token;

#endif
