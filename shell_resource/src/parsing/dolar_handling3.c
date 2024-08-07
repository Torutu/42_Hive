/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolar_handling3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:18:28 by stuna             #+#    #+#             */
/*   Updated: 2024/06/09 15:18:29 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/*
heredoc
*/
static void	help_funct(char *str, char **new_str, int *j, t_hmap **h)
{
	char	*temp;
	int		start;
	char	*value;

	temp = NULL;
	start = *j;
	while (str[*j] != 0
		&& ((ft_isalpha(str[*j]) == 1 || str[*j] == '_'
				|| ft_isdigit(str[*j]) == 1)))
		(*j)++;
	temp = ft_substr(str, start, *j - start);
	if (return_value_hash(*h, temp) != NULL)
	{
		value = ft_strdup(return_value_hash(*h, temp));
		free(temp);
		*new_str = ft_strjoin_new(new_str, &value);
		free(value);
	}
}

static void	dollar_cleaning_hd(char *str, char **new_str, int *j, t_hmap **h)
{
	char	*temp;

	(*j)++;
	temp = NULL;
	if (str[*j] == 0 || (ft_isalpha(str[*j]) == 0 && str[*j] != '_'\
		&& ft_isdigit(str[*j]) == 0))
	{
		temp = ft_strdup("$");
		*new_str = ft_strjoin_new(new_str, &temp);
		free(temp);
	}
	else if (ft_isdigit(str[*j]) == 1)
		(*j)++;
	else
		help_funct(str, new_str, j, h);
}

static void	no_dollar(char *str, int *j, char **new_str)
{
	char	*temp;
	int		start;

	if (str[*j] != '$')
	{
		start = *j;
		while (str[*j] != 0 && str[*j] != '$')
			(*j)++;
		temp = ft_substr(str, start, *j - start);
		*new_str = ft_strjoin_new(new_str, &temp);
	}
}

static char	*here_doc_handle(char *str, int *j, t_hmap **h, int exit_code)
{
	char	*new_str;
	char	*temp;

	new_str = NULL;
	while (str[*j] != 0)
	{
		temp = NULL;
		no_dollar(str, j, &new_str);
		if (str[*j] == '$')
		{
			if (str[*j + 1] == '?')
			{
				temp = ft_strdup(ft_itoa(exit_code));
				new_str = ft_strjoin_new(&new_str, &temp);
				(*j) += 2;
			}
			else
				dollar_cleaning_hd(str, &new_str, j, h);
		}
		if (temp != NULL)
			free(temp);
	}
	return (new_str);
}

void	clean_dlr_hd(char **str, t_hmap	**h, int exit_code)
{
	int		j;
	char	*new_str;
	char	*temp;

	new_str = NULL;
	temp = NULL;
	if (is_in_str(*str, '$', 0, ft_strlen(*str)) == -1)
		return ;
	else
	{
		j = 0;
		while ((*str)[j])
		{
			temp = here_doc_handle(*str, &j, h, exit_code);
			new_str = ft_strjoin_new(&new_str, &temp);
			free(temp);
		}
		free(*str);
		*str = ft_strdup(new_str);
		free(new_str);
	}
}
