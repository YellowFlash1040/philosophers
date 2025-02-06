/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:31:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment_setup.h"

int	setup_environment(t_environment **environment, t_params *params)
{
	*environment = init_environment();
	if (!*environment)
		return (ENV_INIT_ERR);
	if (setup_timings(&(*environment)->timings, params) != 0)
		return (destroy_environment(environment), TIMINGS_INIT_ERR);
	(*environment)->death_mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!(*environment)->death_mutex)
		return (destroy_environment(environment), MUTEX_INIT_ERR);
	(*environment)->write_mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!(*environment)->write_mutex)
		return (destroy_environment(environment), MUTEX_INIT_ERR);
	pthread_mutex_init((*environment)->death_mutex, NULL);
	pthread_mutex_init((*environment)->write_mutex, NULL);
	return (0);
}
