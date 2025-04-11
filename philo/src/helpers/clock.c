/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:04:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 16:27:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clock.h"

#include <stdio.h>

t_uint64	calculate_time_difference(t_time_point start, t_time_point end)
{
	// t_uint64	seconds;
	// t_uint64	microseconds;
	t_uint64	start_time;
	t_uint64	end_time;
	t_uint64	elapsed;

	start_time = start.tv_sec * 1e3 + start.tv_usec / 1e3;
	end_time = end.tv_sec * 1e3 + end.tv_usec / 1e3;
	elapsed = end_time - start_time;

	if (elapsed > 10000)
	{
		printf("Yep, something is wrong\n");
		//
		// printf("start.tv_sec: %ld\n", start.tv_sec);
		// printf("start.tv_usec: %ld\n", start.tv_usec);
		// printf("end.tv_sec: %ld\n", end.tv_sec);
		// printf("end.tv_usec: %ld\n", end.tv_usec);

		// printf("seconds: %ld\n", seconds);
		// printf("microseconds: %ld\n", microseconds);

		printf("start_time: %ld\n", start_time);
		printf("end_time: %ld\n", end_time);
		printf("elapsed: %ld\n", elapsed);
		printf("\n\n");
	}

	return (elapsed);
}

t_uint64	calculate(t_time_point start, t_time_point end)
{
	t_uint64	start_time;
	t_uint64	end_time;
	t_uint64	elapsed;

	start_time = start.tv_sec * 1e3 + start.tv_usec / 1e3;
	end_time = end.tv_sec * 1e3 + end.tv_usec / 1e3;
	elapsed = end_time - start_time;

	return (elapsed);
}

t_uint64	time_elapsed_since(t_time_point start, t_time_point *now_ref)
{
	t_time_point	now;
	t_uint64		time_stamp;

	gettimeofday(&now, NULL);
	time_stamp = calculate(start, now);
	if (now_ref)
		*now_ref = now;
	return (time_stamp);
}

t_uint64 get_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

t_uint64 elapsed_time_ms(t_uint64 start_time)
{
    return get_time_ms() - start_time;
}

#include <unistd.h>

void precise_sleep(t_uint64 duration_ms)
{
    t_uint64 start = get_time_ms();
    while (elapsed_time_ms(start) < duration_ms)
        usleep(500);
}
