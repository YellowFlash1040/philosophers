/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:39:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/30 18:49:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

t_table	*init_table(void)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->forks = NULL;
	return (table);
}

void	destroy_table(t_table **table)
{
	if (!table || !*table)
		return ;
	if ((*table)->forks)
		clear_list((*table)->forks, clear_fork);
	free(*table);
	*table = NULL;
}

void	seat_philosophers_at_the_table(t_circular_list *philosophers,
		t_table *table)
{
	t_circular_list	*forks;
	t_philosopher	*philosopher;
	int				i;

	forks = table->forks;
	i = -1;
	while (++i < philosophers->count)
	{
		philosopher = (t_philosopher *)philosophers->head->value;
		philosopher->left_fork = (t_fork *)forks->head->value;
		philosopher->right_fork = (t_fork *)forks->head->next->value;
		philosophers->head = philosophers->head->next;
		table->forks->head = table->forks->head->next;
	}
}
