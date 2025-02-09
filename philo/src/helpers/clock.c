/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:04:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/09 12:15:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clock.h"

int	calculate_time_difference(t_time_point start, t_time_point end)
{
	long	seconds;
	long	microseconds;
	int		elapsed;

	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapsed = seconds * 1e3 + microseconds / 1e3;
	return (elapsed);
}

int	time_elapsed_since(t_time_point start, t_time_point *now_ref)
{
	t_time_point	now;
	int				time_stamp;

	gettimeofday(&now, NULL);
	time_stamp = calculate_time_difference(start, now);
	if (now_ref)
		*now_ref = now;
	return (time_stamp);
}

int	get_current_time(void)
{
	t_time_point	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	precise_usleep(int milliseconds)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
