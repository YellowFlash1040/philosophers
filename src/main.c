/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 17:04:08 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "simulation_setup.h"

int	main(int argsc, char **args)
{
	t_params			*params;
	t_simulation_data	*data;
	int					result;

	(void)argsc;
	(void)args;
	params = init_params();
	if (!params)
		return (PARAMS_INIT_ERR);
	params->number_of_philosophers = 3;
	params->time_to_eat = 200;
	params->time_to_sleep = 200;
	data = init_simulation_data();
	if (!data)
		return (SIMULATION_DATA_INIT_ERR);
	result = setup_data(data, params);
	destroy_params(&params);
	if (result != 0)
		return (destroy_simulation_data(&data), result);
	start_simulation(data);
	destroy_simulation_data(&data);
	return (0);
}
