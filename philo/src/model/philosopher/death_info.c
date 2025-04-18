/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:02:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:04:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "death_info.h"

t_death_info	*init_death_info(void)
{
	t_death_info	*death_info;

	death_info = (t_death_info *)malloc(sizeof(t_death_info));
	if (!death_info)
		return (NULL);
	death_info->philo_id = -1;
	death_info->timestamp = 0;
	return (death_info);
}

void	destroy_death_info(t_death_info **death_info)
{
	if (!death_info || !*death_info)
		return ;
	free(*death_info);
	*death_info = NULL;
}
