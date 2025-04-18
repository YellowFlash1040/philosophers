/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soul.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:09:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/30 16:44:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soul.h"

t_soul	*init_soul(void)
{
	t_soul	*soul;

	soul = (t_soul *)malloc(sizeof(t_soul));
	if (!soul)
		return (NULL);
	return (soul);
}

void	destroy_soul(t_soul **soul)
{
	if (!soul || !*soul)
		return ;
	free(*soul);
	*soul = NULL;
}
