#include "../inc/philo.h"

int ft_atoi(const char *str)
{
	int i;
	int num;

	num = 0;
	i = 0;
	while(str[i])
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
	}
	return (num);
}
static int	ft_is_num(char *num)
{
	int i = 0;
	while(num[i])
	{
		if(num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_all_num(int ac, char **av)
{
	int i = 1;
	while(i < ac)
	{
		if(!ft_is_num(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args_init(int ac, char **av)
{
	if (!ft_is_all_num(ac,av))
		guide_msg();
}
