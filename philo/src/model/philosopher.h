/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/02 13:20:10 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "action.h"
# include "fork.h"
# include "soul.h"
# include "time_point.h"

typedef pthread_mutex_t	t_mutex;

typedef struct philosopher
{
	int				id;
	t_soul			*soul;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_action		action;
	t_time_point	last_meal_time;
	t_mutex			*last_meal_time_mutex;
	bool			is_eating;
	t_mutex			*is_eating_mutex;
	bool			has_eaten_enough;
	t_mutex			*has_eaten_enough_mutex;
	int				meals_eaten;
}					t_philosopher;

t_philosopher		*init_philosopher(t_action action);
bool				destroy_philosopher(t_philosopher *philosopher);
bool				bring_to_life(t_philosopher *philosopher, void *arg);
bool				wait_for_death(t_philosopher *philosopher);

#endif