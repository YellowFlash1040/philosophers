/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:47:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:43:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actions.h"

static bool	is_someone_died(t_circular_list *list,
				t_uint64 simulation_start, int time_to_die,
				t_death_info *death_info);
static bool	time_is_up(t_philosopher *philosopher,
				t_uint64 simulation_start, int time_to_die,
				t_uint64 *death_timestamp);
static void	handle_death(t_environment *environment, t_death_info *death_info);
bool		has_everyone_eaten_enough(t_circular_list *philosophers);
void		*monitoring(void *arg);

void	start_monitoring(t_monitor *monitor)
{
	t_monitor_data	*monitor_data;

	monitor_data = monitor->monitor_data;
	pthread_create(monitor->soul, NULL, monitoring, (void *)monitor_data);
}

void	*monitoring(void *arg)
{
	t_monitor_data	*monitor_data;
	t_circular_list	*philosophers;
	int				time_to_die;
	bool			someone_died;
	t_death_info	death_info;

	monitor_data = (t_monitor_data *)arg;
	philosophers = monitor_data->philosophers;
	time_to_die = monitor_data->environment->timings->time_to_die;
	someone_died = false;
	while (!someone_died)
	{
		if (is_someone_died(philosophers,
				monitor_data->environment->simulation_start, time_to_die,
				&death_info))
		{
			handle_death(monitor_data->environment, &death_info);
			someone_died = true;
		}
		if (has_everyone_eaten_enough(philosophers))
			break ;
		// usleep(MILLISECOND);
		precise_sleep(1);
	}
	return (NULL);
}

static bool	is_someone_died(t_circular_list *list,
		t_uint64 simulation_start, int time_to_die,
		t_death_info *death_info)
{
	t_circular_list_node	*node;
	t_philosopher			*philosopher;
	bool					has_eaten_enough;
	bool					is_eating;
	int						i;

	node = list->head;
	i = -1;
	while (++i < list->count)
	{
		philosopher = (t_philosopher *)node->value;
		pthread_mutex_lock(philosopher->meal_mutex);
		has_eaten_enough = philosopher->has_eaten_enough;
		is_eating = philosopher->is_eating;
		pthread_mutex_unlock(philosopher->meal_mutex);
		if (!has_eaten_enough && time_is_up(philosopher, simulation_start,
				time_to_die, &(*death_info).timestamp) && !is_eating)
		{
			(*death_info).philo_id = philosopher->id;
			return (true);
		}
		node = node->next;
	}
	return (false);
}

static bool	time_is_up(t_philosopher *philosopher,
		t_uint64 simulation_start, int time_to_die,
		t_uint64 *death_timestamp)
{
	t_uint64	now;
	t_uint64	philosopher_last_meal_time;
	int			starving_time;

	pthread_mutex_lock(philosopher->meal_mutex);
	philosopher_last_meal_time = philosopher->last_meal_time;
	pthread_mutex_unlock(philosopher->meal_mutex);
	if (philosopher_last_meal_time == 0)
		philosopher_last_meal_time = simulation_start;
	now = get_time_ms();
	starving_time = now - philosopher_last_meal_time;
	if (starving_time > time_to_die)
	{
		*death_timestamp = now;
		return (true);
	}
	return (false);
}

static void	handle_death(t_environment *environment, t_death_info *death_info)
{
	t_uint64	simulation_start;
	int				death_timestamp;

	simulation_start = environment->simulation_start;
	pthread_mutex_lock(environment->death_mutex);
	environment->someone_died = true;
	pthread_mutex_unlock(environment->death_mutex);
	death_timestamp = death_info->timestamp - simulation_start;
	pthread_mutex_lock(environment->write_mutex);
	printf("%d %d died\n", death_timestamp, death_info->philo_id);
	pthread_mutex_unlock(environment->write_mutex);
}
