/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:36:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "action.h"
# include "fork.h"
# include "mutex.h"
# include "soul.h"
# include "time_point.h"

typedef struct philosopher
{
	int			id;
	t_soul		*soul;
	t_action	action;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_mutex		*meal_mutex;
	t_uint64	last_meal_time;
	bool		is_eating;
	int			meals_eaten;
	bool		has_eaten_enough;
}	t_philosopher;

t_philosopher	*init_philosopher(t_action action);
bool			destroy_philosopher(t_philosopher *philosopher);
bool			bring_to_life(t_philosopher *philosopher, void *arg);
bool			wait_for_death(t_philosopher *philosopher);

#endif