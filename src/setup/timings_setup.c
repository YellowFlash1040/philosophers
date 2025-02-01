/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:37:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 16:41:28 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timings_setup.h"

static void	fill_timings(t_timings *timings, t_params *params);

int	setup_timings(t_timings **timings, t_params *params)
{
	*timings = init_timings();
	if (!*timings)
		return (TIMINGS_INIT_ERR);
	fill_timings(*timings, params);
	return (0);
}

static void	fill_timings(t_timings *timings, t_params *params)
{
	timings->time_to_eat = params->time_to_eat;
	timings->time_to_sleep = params->time_to_sleep;
	timings->time_to_die = params->time_to_die;
}
