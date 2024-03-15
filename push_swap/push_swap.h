/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:30 by walnaimi          #+#    #+#             */
/*   Updated: 2024/03/13 13:53:22 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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
int     error_syntax(char   *str_n);
int	    ft_isdigit(int c);
int     error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **stack);
//sort_stacks
void    sort_stacks(t_stack_node **a, t_stack_node **b);
//split
char    **split(char *s, char   c);
//stack_init
void    init_stack_a(t_stack_node **a, char **argv);
t_stack_node    *get_cheapest(t_stack_node *stack);
void    prep_for_push(t_stack_node **stack,
                        t_stack_node *top_node,
                        char stack_name);
//stack_utils
int     stack_len(t_stack_node *stack);
bool    stack_sorted(t_stack_node *stack);
t_stack_node *find_last(t_stack_node *stack);
t_stack_node *find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);

//swap
void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss(t_stack_node **a, t_stack_node **b, bool print);
//push
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);
//init_a_to_b
void    current_index(t_stack_node *stack);
void    set_cheapest(t_stack_node *stack);
void    init_nodes_a(t_stack_node *a, t_stack_node *b);
//init_b_to_a
void    init_nodes_b(t_stack_node *a, t_stack_node *b);

//sort_three
void    sort_three(t_stack_node **a);
//rotate
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
//rev_rotate
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);
//push
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

#endif