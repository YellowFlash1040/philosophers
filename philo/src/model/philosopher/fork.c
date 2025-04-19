/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:11:21 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:40:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

t_fork	*init_fork(void)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	if (pthread_mutex_init(fork, NULL) != 0)
		return (free(fork), NULL);
	return (fork);
}

bool	destroy_fork(t_fork **fork)
{
	if (!fork || !*fork)
		return (false);
	if (pthread_mutex_destroy(*fork) != 0)
		return (false);
	free(*fork);
	*fork = NULL;
	return (true);
}
