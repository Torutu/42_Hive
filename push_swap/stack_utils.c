/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:13 by walnaimi          #+#    #+#             */
/*   Updated: 2024/02/29 13:07:28 by walnaimi         ###   ########.fr       */
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
