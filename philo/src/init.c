#include "../inc/philo.h"

int init_forks(t_data *data)
{
	int i;
	t_philo *philos;

	philos = data->philos;
	i = -1;
	while(++i < data->num_of_phil)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].l_f = &data->forks[0];
	philos[0].r_f = &data->forks[data->num_of_phil - 1];
	while (++i < data->num_of_phil)
	{
		philos[i].l_f = &data->forks[i];
		philos[i].r_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo *philos;
	int	i;

	i = 0;
	philos = data->philos;
	while ( i < data->num_of_phil)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].ate = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_ate, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

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
