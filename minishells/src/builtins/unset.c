/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:15:30 by stuna             #+#    #+#             */
/*   Updated: 2024/06/09 15:15:31 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/builtins.h"

/* it needs to work for: unset  key. */
void	ft_unset(t_cmd_data *c, t_hmap **v)
{
	char	*key_to_unset;
	int		i;

	i = 1;
	if (c->args[1] == NULL)
		return ;
	while (c->args[i])
	{
		key_to_unset = take_key(c->args[i]);
		if (key_exists(*v, key_to_unset) == 1)
			remove_var(v, key_to_unset);
		free(key_to_unset);
		i++;
	}
}
