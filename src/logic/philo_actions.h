/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:10:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:41:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "action.h"
# include "clock.h"
# include "status.h"
# include "thread.h"
# include <stdio.h>
# include <unistd.h> //for usleep()

void	*philo_live(void *arg);
void	*philo_eat(void *arg);
void	*philo_think(void *arg);
void	*philo_sleep(void *arg);

#endif