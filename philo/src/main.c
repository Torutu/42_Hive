#include "../inc/philo.h"

int	run_threads(t_data *data)
{
	int i;
	int nums_of_philos;

	nums_of_philos = get_num_philos(data);
	i = -1;
	data->starting_ti = get_time();
	while (++i < nums_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
					&routine, &data->philos[i]))
			return (1);
	}
}

int	philosophising(int ac, char**av, t_data *data)
{
	if(init_data(data, ac, av) != 0)
		return (MALLOC_ERROR);
	init_philos(data);
	init_forks(data);

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
