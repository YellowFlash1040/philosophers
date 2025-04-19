/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:00:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/19 15:55:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actions.h"

bool		is_someone_dead(t_environment *environment);
static bool	take_a_fork(t_thread *thread, t_fork *fork, bool *fork_taken);

bool	print_status(t_thread *thread, t_status status, t_uint64 current_time)
{
	int			time_stamp;
	int			id;
	char		*status_message;

	if (is_someone_dead(thread->environment))
		return (false);
	time_stamp = current_time - thread->environment->simulation_start;
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

bool	wait_for_forks(t_thread *thread, bool *forks_taken)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = thread->philosopher->left_fork;
	right_fork = thread->philosopher->right_fork;
	forks_taken[LEFT] = false;
	forks_taken[RIGHT] = false;
	if (thread->philosopher->id % 2 == 0)
	{
		if (!take_a_fork(thread, left_fork, &forks_taken[LEFT]))
			return (false);
		if (!take_a_fork(thread, right_fork, &forks_taken[RIGHT]))
			return (false);
	}
	else
	{
		if (right_fork)
			if (!take_a_fork(thread, right_fork, &forks_taken[RIGHT]))
				return (false);
		if (!take_a_fork(thread, left_fork, &forks_taken[LEFT]))
			return (false);
	}
	return (forks_taken[LEFT] && forks_taken[RIGHT]);
}

static bool	take_a_fork(t_thread *thread, t_fork *fork, bool *fork_taken)
{
	t_uint64	time_to_die;
	t_uint64	last_meal_time;
	t_uint64	now;

	time_to_die = thread->environment->timings->time_to_die;
	pthread_mutex_lock(fork);
	now = get_time_ms();
	pthread_mutex_lock(thread->philosopher->meal_mutex);
	last_meal_time = thread->philosopher->last_meal_time;
	pthread_mutex_unlock(thread->philosopher->meal_mutex);
	if (now - last_meal_time >= time_to_die)
	{
		pthread_mutex_unlock(fork);
		*fork_taken = false;
		return (false);
	}
	*fork_taken = true;
	return (print_status(thread, HAS_TAKEN_FORK, now));
}

void	put_forks_back(t_thread *thread, bool *forks_taken)
{
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = thread->philosopher->left_fork;
	right_fork = thread->philosopher->right_fork;
	if (thread->philosopher->id % 2 == 0)
	{
		if (forks_taken[LEFT])
			pthread_mutex_unlock(left_fork);
		if (forks_taken[RIGHT])
			pthread_mutex_unlock(right_fork);
	}
	else
	{
		if (forks_taken[RIGHT])
			pthread_mutex_unlock(right_fork);
		if (forks_taken[LEFT])
			pthread_mutex_unlock(left_fork);
	}
}
