/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:00:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 11:54:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philosopher	*init_philosopher(t_action action)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = 0;
	philosopher->soul = init_soul();
	if (!philosopher->soul)
		return (free(philosopher), NULL);
	philosopher->action = action;
	philosopher->left_fork = NULL;
	philosopher->right_fork = NULL;
	philosopher->is_alive = false;
	philosopher->last_meal_time = (t_time_point){0};
	philosopher->meals_eaten = 0;
	return (philosopher);
}

bool	destroy_philosopher(t_philosopher *philosopher)
{
	if (philosopher)
	{
		destroy_soul(&philosopher->soul);
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
	philosopher->is_alive = true;
	return (true);
}

bool	wait_for_death(t_philosopher *philosopher)
{
	if (pthread_join(*(philosopher->soul), NULL) != 0)
		return (false);
	return (true);
}
