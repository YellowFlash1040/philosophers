/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:31:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:43:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actions.h"

bool	has_everyone_eaten_enough(t_circular_list *philosophers)
{
	t_circular_list_node	*philosopher_node;
	t_philosopher			*philosopher;
	int						hungry_philosophers;
	int						i;

	hungry_philosophers = philosophers->count;
	philosopher_node = philosophers->head;
	i = -1;
	while (++i < philosophers->count)
	{
		philosopher = (t_philosopher *)philosopher_node->value;
		pthread_mutex_lock(philosopher->meal_mutex);
		if (philosopher->has_eaten_enough)
			hungry_philosophers--;
		pthread_mutex_unlock(philosopher->meal_mutex);
		philosopher_node = philosopher_node->next;
	}
	if (hungry_philosophers == 0)
		return (true);
	return (false);
}
