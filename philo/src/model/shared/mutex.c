/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:55:58 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/19 15:56:19 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"

t_mutex	*init_mutex(void)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (free(mutex), NULL);
	return (mutex);
}

void	destroy_mutex(t_mutex **mutex_ref)
{
	t_mutex	*mutex;

	if (!mutex_ref || !*mutex_ref)
		return ;
	mutex = *mutex_ref;
	pthread_mutex_destroy(mutex);
	free(mutex);
	*mutex_ref = NULL;
}
