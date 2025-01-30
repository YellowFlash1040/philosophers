/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/29 13:42:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <unistd.h>

static void	wait_for_forks(t_fork *own_fork, t_fork *neighbor_fork);
static void	put_forks_back(t_fork *own_fork, t_fork *neighbor_fork);

void	*philo_live(void *arg)
{
	t_timings	*timings;
	int			i;

	// TODO: create a t_dining structure and pass it into the philo_eat function
	timings = (t_timings *)arg;
	i = -1;
	while (++i < 10)
	{
		philo_think(NULL);
		philo_eat((void *)timings->time_to_eat);
		philo_sleep((void *)timings->time_to_sleep);
	}
	return (NULL);
}

void	*philo_eat(void *arg)
{
	t_dining	*dining;

	dining = (t_dining *)arg;
	wait_for_forks(dining->fork1, dining->fork2);
	write(1, "Eating...\n", 10);
	usleep(dining->time_to_eat);
	put_forks_back(dining->fork1, dining->fork2);
	return (NULL);
}

void	wait_for_forks(t_fork *own_fork, t_fork *neighbor_fork)
{
	pthread_mutex_lock(own_fork);
	pthread_mutex_lock(neighbor_fork);
}

void	put_forks_back(t_fork *own_fork, t_fork *neighbor_fork)
{
	pthread_mutex_unlock(neighbor_fork);
	pthread_mutex_unlock(own_fork);
}

void	*philo_sleep(void *arg)
{
	int	*sleep_duration;

	sleep_duration = (int *)arg;
	write(1, "Sleeping...\n", 12);
	usleep(*sleep_duration);
	return (NULL);
}

void	*philo_think(void *arg)
{
	(void)arg;
	write(1, "Thinking...\n", 12);
	return (NULL);
}
