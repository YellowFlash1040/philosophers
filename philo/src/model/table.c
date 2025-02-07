/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:39:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 12:24:14 by akovtune         ###   ########.fr       */
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
	t_circular_list_node	*forks;
	t_philosopher			*philosopher;
	t_circular_list_node	*philosopher_node;
	int						i;

	forks = table->forks->head;
	philosopher_node = philosophers->head;
	i = -1;
	while (++i < philosophers->count)
	{
		philosopher = (t_philosopher *)philosopher_node->value;
		philosopher->left_fork = (t_fork *)forks->value;
		if (forks->next)
			philosopher->right_fork = (t_fork *)forks->next->value;
		philosopher_node = philosopher_node->next;
		forks = forks->next;
	}
}
