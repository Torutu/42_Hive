#include "../inc/philo.h"

uint64_t        get_die_time(t_data *data)
{
        uint64_t        die_time;

        pthread_mutex_lock(&data->mut_die_t);
        die_time = data->time_to_die;
        pthread_mutex_unlock(&data->mut_die_t);
        return (die_time);
}

uint64_t        get_zzz_time(t_data *data)
{
        uint64_t        sleep_time;

        pthread_mutex_lock(&data->mut_zzz_t);
        sleep_time = data->time_to_zzz;
        pthread_mutex_unlock(&data->mut_zzz_t);
        return (sleep_time);
}

uint64_t        get_eat_time(t_data *data)
{
        uint64_t        eat_time;

        pthread_mutex_lock(&data->mut_eat_t);
        eat_time = data->time_to_eat;
        pthread_mutex_unlock(&data->mut_eat_t);
        return (eat_time);
}

uint64_t        get_last_eat_time(t_philo *philo)
{
        uint64_t        last_eat_time;

        pthread_mutex_lock(&philo->mut_last_eat_time);
        last_eat_time = philo->last_eat_time;
        pthread_mutex_unlock(&philo->mut_last_eat_time);
        return (last_eat_time);
}
