/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:44 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 17:25:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_setup.h"

int	setup_monitor(t_monitor **monitor, t_simulation_data *data)
{
	if (!monitor)
		return (EMPTY_MONITOR_ERR);
	if (!data)
		return (EMPTY_DATA_ERR);
	(*monitor) = init_monitor();
	if (!(*monitor))
		return (MONITOR_INIT_ERR);
	(*monitor)->monitor_data = init_monitor_data();
	if (!(*monitor)->monitor_data)
		return (MONITOR_DATA_INIT_ERR);
	(*monitor)->monitor_data->environment = data->environment;
	(*monitor)->monitor_data->philosophers = data->philosophers;
	return (SUCCESS);
}
