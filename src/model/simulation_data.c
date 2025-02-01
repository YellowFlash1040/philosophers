/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:26:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 17:03:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation_data.h"

t_simulation_data	*init_simulation_data(void)
{
	t_simulation_data	*simulation_data;

	simulation_data = (t_simulation_data *)malloc(sizeof(t_simulation_data));
	if (!simulation_data)
		return (NULL);
	simulation_data->environment = NULL;
	simulation_data->table = NULL;
	simulation_data->philosophers = NULL;
	simulation_data->threads = NULL;
	return (simulation_data);
}

void	destroy_simulation_data(t_simulation_data **data)
{
	t_simulation_data	*simulation_data;

	if (!data || !*data)
		return ;
	simulation_data = *data;
	if (simulation_data->table)
		destroy_table(&simulation_data->table);
	if (simulation_data->philosophers)
		clear_list(simulation_data->philosophers, clear_philosopher);
	if (simulation_data->environment)
		destroy_environment(&simulation_data->environment);
	if (simulation_data->threads)
		clear_list(simulation_data->threads, clear_thread);
	free(simulation_data);
	*data = NULL;
}
