/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:10:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:52:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "action.h"
# include "philosopher_pair.h"
# include "t_dining.h"
# include "timings.h"

void	*philo_live(void *arg);
void	*philo_eat(void *arg);
void	*philo_think(void *arg);
void	*philo_sleep(void *arg);

#endif