/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:45:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 18:41:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	start_simulation(t_simulation_data *data)
{
	t_circular_list_node	*philosophers;
	t_philosopher			*philosopher;
	t_circular_list_node	*threads;
	t_thread				*thread;
	t_time_point			simulation_start;
	int						i;

	philosophers = data->philosophers->head;
	threads = data->threads->head;
	gettimeofday(&simulation_start, NULL);
	i = -1;
	((t_thread *)threads->value)->environment->simulation_start = simulation_start;
	while (++i < data->philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->value;
		thread = (t_thread *)threads->value;
		bring_to_life(philosopher, (void *)thread);
		philosophers = philosophers->next;
		threads = threads->next;
	}
	i = -1;
	while (++i < data->philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->value;
		wait_for_death(philosopher);
		philosophers = philosophers->next;
	}
	return (0);
}
