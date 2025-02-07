/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 15:22:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_data.h"

t_monitor_data	*init_monitor_data(void)
{
	t_monitor_data	*monitor_data;

	monitor_data = (t_monitor_data *)malloc(sizeof(t_monitor_data));
	if (!monitor_data)
		return (NULL);
	monitor_data->philosophers = NULL;
	monitor_data->environment = NULL;
	return (monitor_data);
}

void	destroy_monitor_data(t_monitor_data **monitor_data)
{
	if (!monitor_data || !*monitor_data)
		return ;
	free(*monitor_data);
	*monitor_data = NULL;
}
