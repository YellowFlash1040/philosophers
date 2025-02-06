/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:22:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

t_monitor	*init_monitor(void)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	monitor->soul = init_soul();
	if (!monitor->soul)
		return (NULL);
	monitor->monitor_data = NULL;
	return (monitor);
}

void	destroy_monitor(t_monitor **monitor)
{
	if (!monitor || !*monitor)
		return ;
	destroy_monitor_data(&(*monitor)->monitor_data);
	destroy_soul(&(*monitor)->soul);
	free(*monitor);
	*monitor = NULL;
}
