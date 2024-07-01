#include "../inc/philo.h"

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iterating = data->keep_iter;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iterating);
}

int	get_num_philos(t_data *data)
{
	int num_philos;

	pthread_mutex_lock(&data->mut_nb_ph);
	num_philos = data->num_of_phil;
	pthread_mutex_unlock(&data->mut_nb_ph);
	return(num_philos);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t time;

	pthread_mutex_lock(&data->mut_start_time);
	time = data->starting_ti;
	pthread_mutex_unlock(&data->mut_start_time);
	return (time);
}

t_state get_philo_state(t_philo *philo)
{
	t_state state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}
