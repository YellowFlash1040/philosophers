/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:33:00 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:11:21 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_environment	*init_environment(void)
{
	t_environment	*environment;

	environment = (t_environment *)malloc(sizeof(t_environment));
	if (!environment)
		return (NULL);
	environment->simulation_start = 0;
	environment->someone_died = false;
	environment->timings = NULL;
	environment->death_mutex = NULL;
	environment->write_mutex = NULL;
	environment->meals_required = -1;
	return (environment);
}

void	destroy_environment(t_environment **environment)
{
	if (!environment || !*environment)
		return ;
	if ((*environment)->timings)
		destroy_timings(&(*environment)->timings);
	pthread_mutex_destroy((*environment)->death_mutex);
	pthread_mutex_destroy((*environment)->write_mutex);
	free((*environment)->death_mutex);
	free((*environment)->write_mutex);
	free(*environment);
	*environment = NULL;
}
