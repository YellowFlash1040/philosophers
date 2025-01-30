/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:16:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/26 16:25:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCTORS_H
# define DESTRUCTORS_H

# include "actions.h"
# include "circular_list.h"
# include "philosopher_pair.h"
# include "table.h"

void	clear_philosopher(void *philosopher);
void	clear_table(void *table);
void	clear_philosopher_pair(void *philosopher_pair);

#endif