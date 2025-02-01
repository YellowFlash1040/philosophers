/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:32:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 17:06:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_setup.h"

static bool	create_forks(t_circular_list **list, int amount);

int	setup_table(t_table **table, int forks_amount)
{
	*table = init_table();
	if (!*table)
		return (TABLE_INIT_ERR);
	if (!create_forks(&(*table)->forks, forks_amount))
		return (FORKS_INIT_ERR);
	return (0);
}

static bool	create_forks(t_circular_list **list, int amount)
{
	t_circular_list	*forks;
	t_fork			*fork;
	int				i;

	*list = NULL;
	forks = init_circular_list();
	if (!forks)
		return (false);
	i = -1;
	while (++i < amount)
	{
		fork = init_fork();
		if (!fork)
			return (clear_list(forks, clear_fork), false);
		if (!add_to_list(forks, (void *)fork))
			return (clear_list(forks, clear_fork), false);
	}
	*list = forks;
	return (true);
}
