#include "../inc/philo.h"

int	philosophising(int ac, char**av, t_data *data)
{
	if(init_data(data, ac, av) != 0)
		return (MALLOC_ERROR);
	return 0;
}

int main(int ac, char** av)
{
	if(ac == 5 || ac == 6)
	{
		t_data data;
		check_args_init(ac, av, &data);
		philosophising(ac, av, &data);
	}
	else
		guide_msg();
	return 0;
}
