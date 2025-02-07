/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:06:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 15:35:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation_setup.h"

int	setup_data(t_simulation_data *data, t_params *params)
{
	int	amount;
	int	result;

	amount = params->number_of_philosophers;
	result = setup_environment(&data->environment, params);
	if (result != SUCCESS)
		return (result);
	result = setup_table(&data->table, amount);
	if (result != SUCCESS)
		return (result);
	result = setup_philosophers(&data->philosophers, amount);
	if (result != SUCCESS)
		return (result);
	result = setup_threads(data);
	if (result != SUCCESS)
		return (result);
	result = setup_monitor(&data->monitor, data);
	if (result != SUCCESS)
		return (result);
	seat_philosophers_at_the_table(data->philosophers, data->table);
	return (0);
}
