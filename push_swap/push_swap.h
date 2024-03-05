/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:30 by walnaimi          #+#    #+#             */
/*   Updated: 2024/03/05 19:20:28 by walnaimi         ###   ########.fr       */
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

//error_check
int error_syntax(char   *str_n);
int	ft_isdigit(int c);
int error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **stack);
//sort_stacks
void    sort_stacks(t_stack_node **a, t_stack_node **b);
//split
char    **split(char *s, char   c);
//stack_init
void    init_stack_a(t_stack_node **a, char **argv);
//stack_utils
int     stack_len(t_stack_node *stack);
bool    stack_sorted(t_stack_node *stack);
//swap

//push
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);
//init_a_to_b
void    current_index(t_stack_node *stack);
void    set_cheapest(t_stack_node *stack);
void    init_nodes_a(t_stack_node *a, t_stack_node *b);

#endif