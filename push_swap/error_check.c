/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walnaimi <walnaimi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:35 by walnaimi          #+#    #+#             */
/*   Updated: 2024/02/19 15:43:28 by walnaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int error_syntax(char   *str_n)
{
    if(!(*str_n == '+' || *str_n == '-'
                       || (*str_n >= '0' && *str_n <= '9')))
            return (1);
    if ((*str_n == '+'
                    || *str_n == '-')
            && !(str_n[1] >= '0' && str_n[1] <= '9'))
            return (1);
    while (*++str_n)
    {
        if (!(*str_n >= '0' && *str_n <= '9'))
            return (1);
    }
    return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
int error_duplicate(t_stack_node *a, int n)
{
    if  (!a)
        return(0);
    {
        while(a)
        {
            if(a->nbr == n)
                return(1);
            a = a->next;
        }
    }
    return (0);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;
    t_stack_node    *current;

    if(!stack)
        return (0);
    current = *stack;
    while(current)
    {
        tmp = current->next;
        current->nbr = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}
void    free_errors(t_stack_node **stack)
{
    free_stack(stack);
    write(1, "Error\n", 6);
    exit(1);
}
