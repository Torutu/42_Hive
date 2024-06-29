#include "../inc/philo.h"

void guide_msg()
{
	printf("Wrong input!\n");
	printf("./philo [number_of_philos] [time_to_die] ");
	printf("[time_to_eat] [time_to_sleep] ");
	printf("(optinal)[number_of_meals]\n");
	printf("./philo 4 800 200 200 5\n");
	printf("all of the numbers should be positive");
	exit (0);
}
