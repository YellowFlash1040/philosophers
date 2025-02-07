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
	int			action_result;
	int			i;

	thread = (t_thread *)arg;
	i = -1;
	while (true)
	{
		action_result = philo_think(thread);
		if (action_result != SUCCESS)
			break ;
		action_result = philo_eat(thread);
		if (action_result != SUCCESS)
			break ;
		if (thread->philosopher->meals_eaten == thread->environment->meals_required)
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

	has_both_forks = wait_for_forks(thread, forks_taken);
	if (has_both_forks)
	{
		if (!print_status(thread, EATING, &now))
			return (SOMEONE_DIED);
		thread->philosopher->last_meal_time = now;
		thread->philosopher->meals_eaten++;
		usleep(thread->environment->timings->time_to_eat * MILLISECOND);
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
	usleep(thread->environment->timings->time_to_sleep * MILLISECOND);
	return (SUCCESS);
}

int	philo_think(t_thread *thread)
{
	if (!print_status(thread, THINKING, NULL))
		return (SOMEONE_DIED);
	return (SUCCESS);
}
