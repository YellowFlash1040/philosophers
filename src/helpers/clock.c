/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:04:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 18:35:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clock.h"

double	calculate_time_difference(t_time_point start, t_time_point end)
{
	long	seconds;
	long	microseconds;
	double	elapsed;

	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapsed = seconds + microseconds * 1e-6;
	return (elapsed);
}

int	get_current_time_stamp(t_time_point simulation_start)
{
	t_time_point	now;
	int				time_stamp;

	gettimeofday(&now, NULL);
	time_stamp = calculate_time_difference(simulation_start, now) * 1e6;
	return (time_stamp);
}
