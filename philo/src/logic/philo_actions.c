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
bool	print_status(t_thread *thread, t_status status, t_uint64 current_time);

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
		pthread_mutex_lock(thread->philosopher->meal_mutex);
		has_eaten_enough = thread->philosopher->has_eaten_enough;
		pthread_mutex_unlock(thread->philosopher->meal_mutex);
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
	bool			has_both_forks;
	bool			forks_taken[2];
	int				meals_required;
	t_uint64		now;

	meals_required = thread->environment->meals_required;
	has_both_forks = wait_for_forks(thread, forks_taken);
	if (has_both_forks)
	{
		now = get_time_ms();
		pthread_mutex_lock(thread->philosopher->meal_mutex);
		thread->philosopher->is_eating = true;
		thread->philosopher->meals_eaten++;
		if (thread->philosopher->meals_eaten == meals_required)
			thread->philosopher->has_eaten_enough = true;
		pthread_mutex_unlock(thread->philosopher->meal_mutex);
		if (!print_status(thread, EATING, now))
			return (put_forks_back(thread, forks_taken), SOMEONE_DIED);
		// usleep(thread->environment->timings->time_to_eat * MILLISECOND);
		precise_sleep(thread->environment->timings->time_to_eat);
		pthread_mutex_lock(thread->philosopher->meal_mutex);
		thread->philosopher->is_eating = false;
		thread->philosopher->last_meal_time = now;
		pthread_mutex_unlock(thread->philosopher->meal_mutex);
	}
	put_forks_back(thread, forks_taken);
	if (!has_both_forks)
		return (SOMEONE_DIED);
	return (SUCCESS);
}

static int	philo_sleep(t_thread *thread)
{
	if (!print_status(thread, SLEEPING, get_time_ms()))
		return (SOMEONE_DIED);
	// usleep(thread->environment->timings->time_to_sleep * MILLISECOND);
	precise_sleep(thread->environment->timings->time_to_sleep);
	return (SUCCESS);
}

int	philo_think(t_thread *thread)
{
	if (!print_status(thread, THINKING, get_time_ms()))
		return (SOMEONE_DIED);
	if (thread->philosopher->id % 2 == 1)
		precise_sleep(1);
		// usleep(MILLISECOND);
	return (SUCCESS);
}
