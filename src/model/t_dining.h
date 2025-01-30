/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dining.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:49:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:50:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DINING_H
# define T_DINING_H

# include "fork.h"

typedef struct dining
{
	t_fork	*fork1;
	t_fork	*fork2;
	int		time_to_eat;
}			t_dining;

#endif