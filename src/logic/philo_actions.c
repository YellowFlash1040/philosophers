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

static int	philo_think(t_thread *thread);
static int	philo_eat(t_thread *thread);
static int	philo_sleep(t_thread *thread);
static bool	wait_for_forks(t_thread *thread);
static void	put_forks_back(t_thread *thread);
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
		action_result = philo_sleep(thread);
		if (action_result != SUCCESS)
			break ;
	}
	return (NULL);
}

static int	philo_eat(t_thread *thread)
{
	bool	has_both_forks;

	has_both_forks = wait_for_forks(thread);
	if (has_both_forks)
	{
		if (!print_status(thread, EATING, NULL))
			return (SOMEONE_DIED);
		usleep(thread->environment->timings->time_to_eat * MILLISECOND);
	}
	put_forks_back(thread);
	if (!has_both_forks)
		return (SOMEONE_DIED);
	return (SUCCESS);
}

static bool	wait_for_forks(t_thread *thread)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = thread->philosopher->left_fork;
	right_fork = thread->philosopher->right_fork;
	if (thread->philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(left_fork);
		if (!print_status(thread, HAS_TAKEN_FORK, NULL))
			return (false);
		pthread_mutex_lock(right_fork);
		if (!print_status(thread, HAS_TAKEN_FORK, NULL))
			return (false);
	}
	else
	{
		pthread_mutex_lock(right_fork);
		if (!print_status(thread, HAS_TAKEN_FORK, NULL))
			return (false);
		pthread_mutex_lock(left_fork);
		if (!print_status(thread, HAS_TAKEN_FORK, NULL))
			return (false);
	}
	return (true);
}

static void	put_forks_back(t_thread *thread)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = thread->philosopher->left_fork;
	right_fork = thread->philosopher->right_fork;
	if (thread->philosopher->id % 2 == 0)
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
	}
	else
	{
		pthread_mutex_unlock(right_fork);
		pthread_mutex_unlock(left_fork);
	}
}

static int	philo_sleep(t_thread *thread)
{
	if (!print_status(thread, SLEEPING, NULL))
		return (SOMEONE_DIED);
	usleep(thread->environment->timings->time_to_sleep * MILLISECOND);
	return (SUCCESS);
}

static int	philo_think(t_thread *thread)
{
	if (!print_status(thread, THINKING, NULL))
		return (SOMEONE_DIED);
	return (SUCCESS);
}

bool	print_status(t_thread *thread, t_status status, t_time_point *now_ref)
{
	int		time_stamp;
	int		id;
	char	*status_message;

	if (is_someone_dead(thread->environment))
		return (false);
	time_stamp = time_elapsed_since(thread->environment->simulation_start,
			now_ref);
	id = thread->philosopher->id;
	status_message = get_status_message(status);
	pthread_mutex_lock(thread->environment->write_mutex);
	printf("%d %d %s\n", time_stamp, id, status_message);
	pthread_mutex_unlock(thread->environment->write_mutex);
	return (true);
}

bool	is_someone_dead(t_environment *environment)
{
	bool	result;

	pthread_mutex_lock(environment->death_mutex);
	result = environment->someone_died;
	pthread_mutex_unlock(environment->death_mutex);
	return (result);
}
