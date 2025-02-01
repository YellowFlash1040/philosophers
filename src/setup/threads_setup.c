/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:43:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 17:07:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_setup.h"

static int	create_threads_data(t_simulation_data *data);

int	setup_threads(t_simulation_data *data)
{
	int	result;

	result = create_threads_data(data);
	if (result != 0)
		return (result);
	return (0);
}

static int	create_threads_data(t_simulation_data *data)
{
	t_circular_list_node	*philosophers;
	t_circular_list			*threads;
	t_thread				*thread;
	int						i;

	data->threads = NULL;
	threads = init_circular_list();
	if (!threads)
		return (THREADS_DATA_LIST_INIT_ERR);
	philosophers = data->philosophers->head;
	i = -1;
	while (++i < data->philosophers->count)
	{
		thread = init_thread_data();
		if (!thread)
			return (clear_list(threads, free), THREAD_DATA_INIT_ERR);
		thread->philosopher = philosophers->value;
		thread->environment = data->environment;
		if (!add_to_list(threads, (void *)thread))
			return (clear_list(threads, free), THREAD_DATA_INIT_ERR);
		philosophers = philosophers->next;
	}
	data->threads = threads;
	return (0);
}
