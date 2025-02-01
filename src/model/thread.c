/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:55:25 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 18:36:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

t_thread	*init_thread_data(void)
{
	t_thread	*thread;

	thread = (t_thread *)malloc(sizeof(t_thread));
	if (!thread)
		return (NULL);
	thread->philosopher = NULL;
	thread->environment = NULL;
	return (thread);
}

void	destroy_thread_data(t_thread **thread)
{
	if (!thread || !*thread)
		return ;
	free(*thread);
	*thread = NULL;
}
