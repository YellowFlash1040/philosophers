/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:00:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:05:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actions.h"

bool	print_status(t_thread *thread, t_status status, t_time_point *now_ref);
bool	is_someone_dead(t_environment *environment);

int	philo_think(t_thread *thread)
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
