/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:13 by walnaimi          #+#    #+#             */
/*   Updated: 2024/03/04 19:35:49 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     stack_len(t_stack_node *stack)
{
    int count;
    
    if (!stack)
        return(0);
    count = 0;
    while(stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

bool    stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}
