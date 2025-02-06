/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:11:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:41:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actions.h"

static void	wait_for_forks(t_thread *thread);
static void	put_forks_back(t_thread *thread);

void	*philo_live(void *arg)
{
	t_thread	*thread;
	int			i;

	thread = (t_thread *)arg;
	i = -1;
	while (++i < 8)
	{
		if (thread->philosopher->is_alive)
			philo_think(arg);
		if (thread->philosopher->is_alive)
			philo_eat(arg);
		if (thread->philosopher->is_alive)
			philo_sleep(arg);
	}
	return (NULL);
}

void	*philo_eat(void *arg)
{
	t_thread	*thread;
	int			time_stamp;

	thread = (t_thread *)arg;
	wait_for_forks(thread);
	time_stamp = get_current_time_stamp(thread->environment->simulation_start);
	// thread->last_ate = time_stamp;
	printf("%d %d is eating\n", time_stamp, thread->philosopher->id);
	usleep(thread->environment->timings->time_to_eat);
	put_forks_back(thread);
	return (NULL);
}

static void	wait_for_forks(t_thread *thread)
{
	t_fork	*left_fork;
	t_fork	*right_fork;
	int		time_stamp;

	left_fork = thread->philosopher->left_fork;
	right_fork = thread->philosopher->right_fork;
	if (thread->philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(left_fork);
		time_stamp = get_current_time_stamp(thread->environment->simulation_start);
		printf("%d %d has taken a fork\n", time_stamp, thread->philosopher->id);
		pthread_mutex_lock(right_fork);
		time_stamp = get_current_time_stamp(thread->environment->simulation_start);
		printf("%d %d has taken a fork\n", time_stamp, thread->philosopher->id);
	}
	else
	{
		pthread_mutex_lock(right_fork);
		time_stamp = get_current_time_stamp(thread->environment->simulation_start);
		printf("%d %d has taken a fork\n", time_stamp, thread->philosopher->id);
		pthread_mutex_lock(left_fork);
		time_stamp = get_current_time_stamp(thread->environment->simulation_start);
		printf("%d %d has taken a fork\n", time_stamp, thread->philosopher->id);
	}
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

void	*philo_sleep(void *arg)
{
	t_thread	*thread;
	int			time_stamp;

	thread = (t_thread *)arg;
	time_stamp = get_current_time_stamp(thread->environment->simulation_start);
	printf("%d %d  is sleeping\n", time_stamp, thread->philosopher->id);
	usleep(thread->environment->timings->time_to_sleep);
	return (NULL);
}

void	*philo_think(void *arg)
{
	t_thread	*thread;
	int			time_stamp;

	thread = (t_thread *)arg;
	time_stamp = get_current_time_stamp(thread->environment->simulation_start);
	printf("%d %d is thinking\n", time_stamp, thread->philosopher->id);
	return (NULL);
}

void	*philo_die(void *arg)
{
	(void)arg;
	return (NULL);
}

void	print_status(t_thread *thread, t_status status, t_time_point *now_ref)
{
	int		time_stamp;
	int		id;
	char	*status_message;

	if (is_someone_died(thread->environment))
		return ;
	time_stamp = time_elapsed_since(thread->environment->simulation_start,
			now_ref);
	id = thread->philosopher->id;
	status_message = get_status_message(status);
	pthread_mutex_lock(thread->environment->write_mutex);
	printf("%d %d %s\n", time_stamp, id, status_message);
	pthread_mutex_unlock(thread->environment->write_mutex);
}
