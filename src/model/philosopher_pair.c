/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_pair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:41:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 17:44:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_pair.h"

t_philosopher_pair	*init_philosopher_pair(t_philosopher *p1, t_philosopher *p2)
{
	t_philosopher_pair	*pair;

	if (!p1 || !p2)
		return (NULL);
	pair = (t_philosopher_pair *)malloc(sizeof(t_philosopher_pair));
	if (!pair)
		return (NULL);
	pair->philosopher = p1;
	pair->right_neighbor = p2;
	return (pair);
}

void	destroy_philosopher_pair(t_philosopher_pair *pair)
{
	free(pair);
}
