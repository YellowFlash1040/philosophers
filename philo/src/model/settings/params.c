/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:24:15 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 16:10:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

t_params	*init_params(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->number_of_philosophers = 0;
	params->time_to_eat = 0;
	params->time_to_sleep = 0;
	params->time_to_die = 0;
	params->meals_required = -1;
	return (params);
}

void	destroy_params(t_params **params)
{
	if (!params || !*params)
		return ;
	free(*params);
	*params = NULL;
}
