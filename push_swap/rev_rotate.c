/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:31:03 by walnaimi          #+#    #+#             */
/*   Updated: 2024/03/15 17:35:23 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void    rev_rotate(t_stack_node **stack)
{
    t_stack_node *last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_last(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void    rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        write(1, "rrr\n", 4);
}
