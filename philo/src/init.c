#include "../inc/philo.h"

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_phil);
	if (!data->philos)
		return (MALLOC_ERROR);
	printf("Allocated %zu bytes for philos\n", sizeof(t_philo) * data->num_of_phil);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_phil);
	if (!data->forks)
		return (free(data->philos), MALLOC_ERROR);
	data->philo_ths = malloc(sizeof(pthread_t) * data->num_of_phil);
	if (!data->philo_ths)
		return (free(data->philos), free(data->forks), MALLOC_ERROR);
	return (0);
}

int	init_data(t_data *data,int ac,char **av)
{
	data->num_full_ph = 0;
	data->keep_iter = true;
	data->num_of_phil = ft_atoi(av[1]);
	data->time_to_die = (u_int64_t) ft_atoi(av[2]);
	data->time_to_eat = (u_int64_t) ft_atoi(av[3]);
	data->time_to_zzz = (u_int64_t) ft_atoi(av[4]);
	data->num_of_meal = -1;
	if (ac == 6)
		data->num_of_meal = ft_atoi(av[5]);
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_zzz_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_ph, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	return(malloc_data(data));
}
