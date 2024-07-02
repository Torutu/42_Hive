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
	if (pthread_create(&data->monit_all_alive, NULL,
				&all_alive_routine, data))
		return (1);
	if (nb_meals_option(data) == true
			&& pthread_create(&data->monit_all_full, NULL,
				&all_full_routine, data))
		return (1);
	return (0);
}

int     join_threads(t_data *data)
{
        int     i;
        int     nb_philos;

        nb_philos = get_num_philos(data);
        i = -1;
        if (pthread_join(data->monit_all_alive, NULL))
                return (1);
        if (nb_meals_option(data) == true
                && pthread_join(data->monit_all_full, NULL))
                return (1);
        while (++i < nb_philos)
        {
                if (pthread_join(data->philo_ths[i], NULL))
                        return (1);
        }
        return (0);
}

int	philosophising(int ac, char**av, t_data *data)
{
	if(init_data(data, ac, av) != 0)
		return (MALLOC_ERROR);
	init_philos(data);
	init_forks(data);
	run_threads(data);
	join_threads(data);
    free_data(data);
    return (0);
}

void leaks(void)
{
	system("leaks philo");
}

int main(int ac, char** av)
{
	if(ac == 5 || ac == 6)
	{
		t_data data;
		check_args_init(ac, av);
		philosophising(ac, av, &data);
	}
	else
		guide_msg();
	return 0;
}
