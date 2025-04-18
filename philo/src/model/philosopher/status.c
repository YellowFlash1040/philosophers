/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:37:28 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:39:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

char	*get_status_message(t_status status)
{
	if (status == THINKING)
		return ("is thinking");
	if (status == HAS_TAKEN_FORK)
		return ("has taken a fork");
	if (status == EATING)
		return ("is eating");
	if (status == SLEEPING)
		return ("is sleeping");
	if (status == DIED)
		return ("died");
	return ("");
}
