/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:04:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/19 15:54:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clock.h"

t_uint64	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_uint64	time_elapsed_since(t_uint64 start_time)
{
	return (get_time_ms() - start_time);
}

void	precise_sleep(t_uint64 duration_ms)
{
	t_uint64	start;

	start = get_time_ms();
	while (time_elapsed_since(start) < duration_ms)
		usleep(500);
}
