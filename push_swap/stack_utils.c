#include "push_swap.h"

int     stack_len(t_stack_node *stack)
{
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