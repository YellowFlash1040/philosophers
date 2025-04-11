/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:00:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 16:07:32 by akovtune         ###   ########.fr       */
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
	philosopher->last_meal_time = (t_time_point){0};
	philosopher->last_meal_time_mutex = init_fork();
	if (!philosopher->last_meal_time_mutex)
		return (destroy_philosopher(philosopher), NULL);
	philosopher->is_eating = false;
	philosopher->is_eating_mutex = init_fork();
	if (!philosopher->is_eating_mutex)
		return (destroy_philosopher(philosopher), NULL);
	philosopher->meals_eaten = 0;
	philosopher->has_eaten_enough = false;
	philosopher->has_eaten_enough_mutex = init_fork();
	if (!philosopher->has_eaten_enough_mutex)
		return (destroy_philosopher(philosopher), NULL);
	return (philosopher);
}

bool	destroy_philosopher(t_philosopher *philosopher)
{
	if (philosopher)
	{
		destroy_soul(&philosopher->soul);
		if (philosopher->last_meal_time_mutex)
			destroy_fork(&philosopher->last_meal_time_mutex);
		if (philosopher->has_eaten_enough_mutex)
			destroy_fork(&philosopher->has_eaten_enough_mutex);
		if (philosopher->is_eating_mutex)
			destroy_fork(&philosopher->is_eating_mutex);
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
