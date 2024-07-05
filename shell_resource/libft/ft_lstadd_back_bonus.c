/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:24:12 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/18 13:08:44 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*add the node(new) to the end of the list(lst)*/

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*temp;

	if (!lst || !new_lst)
		return ;
	if (!(*lst))
	{
		*lst = new_lst;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_lst;
}
