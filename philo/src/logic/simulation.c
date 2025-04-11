/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:45:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/03/30 18:36:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	launch_timer(t_monitor *monitor);
static void	spawn_philosophers(t_simulation_data *data);
static void	collect_corpses(t_circular_list *list);
static void	stop_timer(t_simulation_data *data);

void	start_simulation(t_simulation_data *data)
{
	launch_timer(data->monitor);
	spawn_philosophers(data);
	collect_corpses(data->philosophers);
	stop_timer(data);
}

static void	launch_timer(t_monitor *monitor)
{
	t_time_point	now;
	t_environment	*environment;

	environment = monitor->monitor_data->environment;
	gettimeofday(&now, NULL);
	environment->simulation_start = now;
	start_monitoring(monitor);
}

static void	spawn_philosophers(t_simulation_data *data)
{
	t_circular_list_node	*philosopher_node;
	t_circular_list_node	*thread_node;
	t_philosopher			*philosopher;
	void					*thread;
	int						i;

	philosopher_node = data->philosophers->head;
	thread_node = data->threads->head;
	i = -1;
	while (++i < data->philosophers->count)
	{
		thread = thread_node->value;
		philosopher = (t_philosopher *)philosopher_node->value;
		pthread_mutex_lock(philosopher->last_meal_time_mutex);
		philosopher->last_meal_time = data->environment->simulation_start;
		pthread_mutex_unlock(philosopher->last_meal_time_mutex);
		bring_to_life(philosopher, thread);
		philosopher_node = philosopher_node->next;
		thread_node = thread_node->next;
	}
}

static void	collect_corpses(t_circular_list *list)
{
	t_circular_list_node	*philosophers;
	t_philosopher			*philosopher;
	int						i;

	i = -1;
	philosophers = list->head;
	while (++i < list->count)
	{
		philosopher = (t_philosopher *)philosophers->value;
		wait_for_death(philosopher);
		philosophers = philosophers->next;
	}
}

static void	stop_timer(t_simulation_data *data)
{
	t_monitor	*monitor;

	monitor = data->monitor;
	pthread_join(*(monitor->soul), NULL);
}
