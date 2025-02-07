/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:45:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 12:25:48 by akovtune         ###   ########.fr       */
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
	t_circular_list_node	*philosophers;
	t_philosopher			*philosopher;
	t_circular_list_node	*thread;
	int						i;

	philosophers = data->philosophers->head;
	thread = data->threads->head;
	i = -1;
	while (++i < data->philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->value;
		philosopher->last_meal_time = data->environment->simulation_start;
		bring_to_life(philosopher, thread->value);
		philosophers = philosophers->next;
		thread = thread->next;
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
