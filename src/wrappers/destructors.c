/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:17:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 17:50:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destructors.h"

void	clear_philosopher(void *value)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)value;
	destroy_philosopher(philosopher);
}

void	clear_philosopher_pair(void *value)
{
	t_philosopher_pair	*pair;

	pair = (t_philosopher_pair *)value;
	destroy_philosopher_pair(pair);
}
