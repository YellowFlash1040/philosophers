/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:47:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:04:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actions.h"

static bool	is_someone_died(t_circular_list *list, int time_to_die,
				t_death_info *death_info);
static bool	time_is_up(t_philosopher *philosopher, int time_to_die,
				t_time_point *death_timestamp);
static void	handle_death(t_environment *environment, t_death_info *death_info);
void		*monitoring(void *arg);

void	start_monitoring(t_monitor *monitor)
{
	t_monitor_data	*monitor_data;
	t_soul			*soul;

	soul = monitor->soul;
	monitor_data = monitor->monitor_data;
	pthread_create(soul, NULL, monitoring, (void *)monitor_data);
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
		if (is_someone_died(philosophers, time_to_die, &death_info))
		{
			handle_death(monitor_data->environment, &death_info);
			someone_died = true;
		}
	}
	return (NULL);
}

static bool	is_someone_died(t_circular_list *list, int time_to_die,
		t_death_info *death_info)
{
	t_circular_list_node	*philosophers;
	t_philosopher			*philosopher;
	int						i;

	philosophers = list->head;
	i = -1;
	while (++i < list->count)
	{
		philosopher = (t_philosopher *)philosophers->value;
		if (time_is_up(philosopher, time_to_die, &(*death_info).timestamp))
		{
			(*death_info).philo_id = philosopher->id;
			return (true);
		}
		philosophers = philosophers->next;
	}
	return (false);
}

static bool	time_is_up(t_philosopher *philosopher, int time_to_die,
		t_time_point *death_timestamp)
{
	t_time_point	now;
	int				starving_time;

	gettimeofday(&now, NULL);
	starving_time = calculate_time_difference_in_ms(philosopher->last_meal_time,
			now);
	if (starving_time > time_to_die)
	{
		*death_timestamp = now;
		return (true);
	}
	return (false);
}

static void	handle_death(t_environment *environment, t_death_info *death_info)
{
	t_time_point	simulation_start;
	int				death_timestamp;

	simulation_start = environment->simulation_start;
	pthread_mutex_lock(environment->death_mutex);
	environment->someone_died = true;
	pthread_mutex_unlock(environment->death_mutex);
	death_timestamp = calculate_time_difference_in_ms(simulation_start,
			death_info->timestamp);
	pthread_mutex_lock(environment->write_mutex);
	printf("%d %d died\n", death_timestamp, death_info->philo_id);
	pthread_mutex_unlock(environment->write_mutex);
}
