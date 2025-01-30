/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:18 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:43:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "action.h"
# include "fork.h"
# include "soul.h"
# include <unistd.h>

typedef struct philosopher
{
	t_soul		*soul;
	t_fork		*fork;
	t_action	action;
}				t_philosopher;

t_philosopher	*init_philosopher(t_action action);
bool			destroy_philosopher(t_philosopher *philosopher);
bool			bring_to_life(t_philosopher *philosopher, void *arg);
bool			wait_for_death(t_philosopher *philosopher);

#endif