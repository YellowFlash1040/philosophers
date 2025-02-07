/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 11:54:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "action.h"
# include "fork.h"
# include "soul.h"
# include "time_point.h"

typedef struct philosopher
{
	int				id;
	t_soul			*soul;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_action		action;
	bool			is_alive;
	t_time_point	last_meal_time;
	int				meals_eaten;
}					t_philosopher;

t_philosopher		*init_philosopher(t_action action);
bool				destroy_philosopher(t_philosopher *philosopher);
bool				bring_to_life(t_philosopher *philosopher, void *arg);
bool				wait_for_death(t_philosopher *philosopher);

#endif