/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 17:02:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actions.h"

int			philo_think(t_thread *thread);
static int	philo_eat(t_thread *thread);
static int	philo_sleep(t_thread *thread);
bool		wait_for_forks(t_thread *thread, bool *forks_taken);
void		put_forks_back(t_thread *thread, bool *forks_taken);
bool		is_someone_dead(t_environment *environment);
bool		print_status(t_thread *thread, t_status status,
				t_time_point *now_ref);

void	*philo_live(void *arg)
{
	t_thread	*thread;
	bool		has_eaten_enough;
	int			action_result;
	int			i;

	thread = (t_thread *)arg;
	i = -1;
	while (true)
	{
		action_result = philo_think(thread);
		if (action_result != SUCCESS)
			break ;
		pthread_mutex_lock(thread->philosopher->has_eaten_enough_mutex);
		has_eaten_enough = thread->philosopher->has_eaten_enough;
		pthread_mutex_unlock(thread->philosopher->has_eaten_enough_mutex);
		if (has_eaten_enough)
			break ;
		action_result = philo_eat(thread);
		if (action_result != SUCCESS)
			break ;
		action_result = philo_sleep(thread);
		if (action_result != SUCCESS)
			break ;
	}
	return (NULL);
}

static int	philo_eat(t_thread *thread)
{
	t_time_point	now;
	bool			has_both_forks;
	bool			forks_taken[2];
	int				meals_required;

	meals_required = thread->environment->meals_required;
	has_both_forks = wait_for_forks(thread, forks_taken);
	// if (has_both_forks)
	// 	printf("has both forks: true\n");
	// else
	// 	printf("has both forks: false\n");
	usleep(MILLISECOND);
	if (has_both_forks)
	{
		// printf("SOMEHOW HE HAS 2 forks\n");
		pthread_mutex_lock(thread->philosopher->is_eating_mutex);
		// printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
		thread->philosopher->is_eating = true;
		pthread_mutex_unlock(thread->philosopher->is_eating_mutex);
		if (!print_status(thread, EATING, &now))
			return (put_forks_back(thread, forks_taken), SOMEONE_DIED);
		// usleep(thread->environment->timings->time_to_eat * MILLISECOND);
		precise_sleep(thread->environment->timings->time_to_eat);
		time_elapsed_since(thread->environment->simulation_start, &now);
		pthread_mutex_lock(thread->philosopher->is_eating_mutex);
		thread->philosopher->is_eating = false;
		pthread_mutex_unlock(thread->philosopher->is_eating_mutex);
		pthread_mutex_lock(thread->philosopher->last_meal_time_mutex);
		thread->philosopher->last_meal_time = now;
		pthread_mutex_unlock(thread->philosopher->last_meal_time_mutex);
		thread->philosopher->meals_eaten++;
		if (thread->philosopher->meals_eaten == meals_required)
		{
			pthread_mutex_lock(thread->philosopher->has_eaten_enough_mutex);
			thread->philosopher->has_eaten_enough = true;
			pthread_mutex_unlock(thread->philosopher->has_eaten_enough_mutex);
		}
	}
	put_forks_back(thread, forks_taken);
	if (!has_both_forks)
		return (SOMEONE_DIED);
	return (SUCCESS);
}

static int	philo_sleep(t_thread *thread)
{
	if (!print_status(thread, SLEEPING, NULL))
		return (SOMEONE_DIED);
	// usleep(thread->environment->timings->time_to_sleep * MILLISECOND);
	precise_sleep(thread->environment->timings->time_to_sleep);
	return (SUCCESS);
}

int	philo_think(t_thread *thread)
{
	if (!print_status(thread, THINKING, NULL))
		return (SOMEONE_DIED);
	if (thread->philosopher->id % 2 == 1)
		usleep(MILLISECOND);
		// precise_sleep(1);
	return (SUCCESS);
}
