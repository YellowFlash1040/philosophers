/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:38:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/30 12:57:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timings.h"

t_timings	*init_timings(void)
{
	t_timings	*timings;

	timings = (t_timings *)malloc(sizeof(t_timings));
	if (!timings)
		return (NULL);
	timings->time_to_eat = 0;
	timings->time_to_sleep = 0;
	timings->time_to_die = 0;
	return (timings);
}

void	destroy_timings(t_timings **timings)
{
	if (!timings || !*timings)
		return ;
	free(*timings);
	*timings = NULL;
}
