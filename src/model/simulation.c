/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:45:03 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:56:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destructors.h"
#include "simulation.h"

bool	create_philosophers(t_circular_list **list, int amount)
{
	t_circular_list	*philosophers;
	t_philosopher	*philosopher;
	int				i;

	*list = NULL;
	philosophers = init_circular_list();
	if (!philosophers)
		return (false);
	i = -1;
	while (++i < amount)
	{
		philosopher = init_philosopher(philo_live);
		if (!philosopher)
			return (clear_list(philosophers, clear_philosopher), false);
		if (!add_to_list(philosophers, (void *)philosopher))
			return (clear_list(philosophers, clear_philosopher), false);
	}
	*list = philosophers;
	return (true);
}

void	destroy_philosophers(t_circular_list **philosophers)
{
	clear_list(*philosophers, clear_philosopher);
	*philosophers = NULL;
}

void	start_simulation(t_simulation_data *data)
{
	t_circular_list		*philosophers;
	t_table				*table;
	t_philosopher		*philosopher;
	t_philosopher_pair	*pair;
	int					i;

	// TODO: I need to bring the "data" argument into the philosopher->action function,
	// but I need to figure out how I can also bring information about t_dining
	philosophers = data->philosophers;
	table = data->table;
	i = -1;
	while (++i < philosophers->count)
	{
		pair = (t_philosopher_pair *)table->pairs->head->value;
		bring_to_life(pair->philosopher, (void *)pair);
		table->pairs->head = table->pairs->head->next;
	}
	i = -1;
	while (++i < philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->head->value;
		wait_for_death(philosopher);
		philosophers->head = philosophers->head->next;
	}
}
