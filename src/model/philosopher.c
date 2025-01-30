/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:00:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:51:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philosopher	*init_philosopher(t_action action)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->soul = init_soul();
	if (!philosopher->soul)
		return (free(philosopher), NULL);
	philosopher->fork = init_fork();
	if (!philosopher->fork)
		return (free(philosopher->soul), free(philosopher), NULL);
	philosopher->action = action;
	return (philosopher);
}

bool	destroy_philosopher(t_philosopher *philosopher)
{
	if (philosopher)
	{
		if (!destroy_fork(philosopher->fork))
			return (false);
		destroy_soul(philosopher->soul);
		free(philosopher);
		return (true);
	}
	return (false);
}

bool	bring_to_life(t_philosopher *philosopher, void *arg)
{
	if (!philosopher)
		return (false);
	if (pthread_create(philosopher->soul, NULL, philosopher->action, arg) != 0)
		return (false);
	return (true);
}

bool	wait_for_death(t_philosopher *philosopher)
{
	if (pthread_join(*(philosopher->soul), NULL) != 0)
		return (false);
	return (true);
}
