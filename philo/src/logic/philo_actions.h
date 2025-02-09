/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:10:57 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/09 12:42:20 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTIONS_H
# define PHILO_ACTIONS_H

# include "action.h"
# include "clock.h"
# include "global_status_codes.h"
# include "status.h"
# include "thread.h"
# include <stdio.h>

# define SOMEONE_DIED 1

void	*philo_live(void *arg);

#endif