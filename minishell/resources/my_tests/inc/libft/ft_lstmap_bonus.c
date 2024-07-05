/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:53:03 by walnaimi          #+#    #+#             */
/*   Updated: 2023/11/18 15:13:53 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/

static t_list	*ft_delend(void *pick, t_list *new_l, void (*del)(void *))
{
	del(pick);
	ft_lstclear(&new_l, (*del));
	return (new_l);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_n;
	void	*pick;

	if (!lst || !f || !del)
		return (0);
	new_l = NULL;
	while (lst)
	{
		pick = f(lst->content);
		if (!pick)
		{
			return (ft_delend(pick, new_l, del));
		}
		new_n = ft_lstnew(pick);
		if (!new_n)
		{
			return (ft_delend(pick, new_l, del));
		}
		ft_lstadd_back(&new_l, new_n);
		lst = lst->next;
	}
	return (new_l);
}
