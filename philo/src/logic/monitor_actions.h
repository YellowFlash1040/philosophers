/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:47:11 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 13:40:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_ACTIONS_H
# define MONITOR_ACTIONS_H

# include "death_info.h"
# include "monitor.h"
# include "philosopher.h"
# include "time_point.h"
# include <stdio.h>
# include <unistd.h>

void	start_monitoring(t_monitor *monitor);

#endif
