/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_pair.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:40:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 17:44:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_PAIR_H
# define PHILOSOPHER_PAIR_H

# include "philosopher.h"

typedef struct philosopher_pair
{
	t_philosopher	*philosopher;
	t_philosopher	*right_neighbor;
}					t_philosopher_pair;

t_philosopher_pair	*init_philosopher_pair(t_philosopher *p1,
						t_philosopher *p2);
void				destroy_philosopher_pair(t_philosopher_pair *pair);

#endif