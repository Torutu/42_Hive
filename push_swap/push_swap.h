/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:30 by walnaimi          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:31 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
    int                  nbr;
    int                  index;
    int                  push_cost;
    bool                 above_median;
    bool                 cheapest;
    struct  s_stack_node *target_node;
    struct  s_stack_node *next;
    struct  s_stack_node *prev;
}   t_stack_node;

#endif