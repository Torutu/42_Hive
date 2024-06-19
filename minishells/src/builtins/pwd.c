/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:15:12 by stuna             #+#    #+#             */
/*   Updated: 2024/06/09 15:15:14 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/builtins.h"

void	ft_pwd(t_cmd_env *c)
{
	char	*pwd;

	if (get_value_hmap(c->hashmap, "PWD"))
		pwd = (get_value_hmap(c->hashmap, "PWD"))->value;
	else
		pwd = c->pwd;
	if (!pwd)
		exit(EXIT_FAILURE);
	printf("%s\n", pwd);
}
/*
void	ft_pwd(t_cmd_env *c)
{
	char	*pwd;

	pwd = c->pwd;
	if (!pwd)
		exit(EXIT_FAILURE);
	else
		printf("%s\n", pwd);
}*/
