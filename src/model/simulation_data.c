/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:39:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation_data.h"

t_simulation_data	*init_simulation_data(void)
{
	t_simulation_data	*simulation_data;

	simulation_data = (t_simulation_data *)malloc(sizeof(simulation_data));
	if (!simulation_data)
		return (NULL);
	simulation_data->timings = init_timings();
	if (!simulation_data->timings)
		return (free(simulation_data), NULL);
	simulation_data->table = NULL;
	simulation_data->philosophers = NULL;
	return (simulation_data);
}
