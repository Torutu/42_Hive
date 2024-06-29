#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include <inttypes.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

/*
 * num_of_phil: 
 *	number of philosophers and also the numbers of forks
 * time_to_die:
 *	the amount of time a philosopher would die if they didn't eat since
 * time_to_eat:
 *  the time it takes for a philosopher to eat.(they need two forks)
 * time_to_zzz:
 *  the time a philosopher will spend sleeping.
 * (optional)min_to_eats:
 *  if all philosophers eat AT LEAST this amount then the simulation stops.
 *  if left empty the simulation stops when a philosopher dies.
 */

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5,
} t_state;

struct s_data;

typedef struct	s_philo
{
	int	id;
	int	ate;
	pthread_mutex_t *l_f;
	pthread_mutex_t *r_f;
	pthread_mutex_t mut_state;
	pthread_mutex_t mut_ate;
	pthread_mutex_t mut_last_eat_time;
	u_int64_t		last_eat_time;
	t_state			state;
	struct s_data	*data;
}t_philo;

typedef struct s_data
{
	int				num_of_phil;
	int				num_of_meal;
	int				num_full_ph;
	bool			keep_iter;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_die;
	u_int64_t		time_to_zzz;
	u_int64_t		starting_ti;
	pthread_mutex_t mut_eat_t;
	pthread_mutex_t mut_die_t;
	pthread_mutex_t mut_zzz_t;
	pthread_mutex_t mut_print;
	pthread_mutex_t mut_nb_ph;
	pthread_mutex_t mut_keep_iter;
	pthread_mutex_t mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}			t_data;

//------MAIN.C
int		philosophising(int ac, char **av, t_data *data);
//------CHECK_ARGS_INIT.C
void	check_args_init(int ac, char **av, t_data *data);
int		ft_atoi(const char *str);
//------ERROR.C
void	guide_msg();
//------INIT.C
int		init_data(t_data *data,int ac,char **av);
int		malloc_data(t_data *data);

# endif
