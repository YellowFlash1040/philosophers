/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:39:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 17:50:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destructors.h"
#include "table.h"

t_table	*init_table(void)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->pairs = init_circular_list();
	if (!table->pairs)
		return (free(table), NULL);
	return (table);
}

void	destroy_table(t_table **table)
{
	clear_list((*table)->pairs, clear_philosopher_pair);
	free(*table);
	*table = NULL;
}

bool	seat_philosophers_at_the_table(t_circular_list *philosophers,
		t_table *table)
{
	t_philosopher		*philosopher;
	t_philosopher		*neighbor;
	t_philosopher_pair	*pair;
	int					i;

	i = -1;
	while (++i < philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->head->value;
		neighbor = (t_philosopher *)philosophers->head->next->value;
		pair = init_philosopher_pair(philosopher, neighbor);
		if (!pair)
			return (false);
		if (!add_to_list(table->pairs, (void *)pair))
			return (clear_list(table->pairs, clear_philosopher_pair), false);
		philosophers->head = philosophers->head->next;
	}
	return (true);
}
