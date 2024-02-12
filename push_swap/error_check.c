#include    "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
int error_duplicate(t_stack_node *a, int n)
{
    while(a)
    {
        if(a->nbr == n)
            return(1);
        a = a->next;
    }
    return(0)
}
