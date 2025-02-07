/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:17:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:40:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destructors.h"

void	clear_philosopher(void *value)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)value;
	destroy_philosopher(philosopher);
}

void	clear_fork(void *value)
{
	t_fork	*fork;

	fork = (t_fork *)value;
	destroy_fork(&fork);
}

void	clear_thread(void *value)
{
	t_thread	*thread;

	thread = (t_thread *)value;
	destroy_thread_data(&thread);
}
