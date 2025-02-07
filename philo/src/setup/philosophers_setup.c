/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:25:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 16:30:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_setup.h"

static bool	create_philosophers(t_circular_list **list, int amount);

int	setup_philosophers(t_circular_list **philosophers, int amount)
{
	if (!create_philosophers(philosophers, amount))
		return (PHILOSOPHERS_INIT_ERR);
	return (0);
}

static bool	create_philosophers(t_circular_list **list, int amount)
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
		philosopher = init_philosopher(PHILOSOPHER_ACTION);
		philosopher->id = i + 1;
		if (!philosopher)
			return (clear_list(philosophers, clear_philosopher), false);
		if (!add_to_list(philosophers, (void *)philosopher))
			return (clear_list(philosophers, clear_philosopher), false);
	}
	*list = philosophers;
	return (true);
}
